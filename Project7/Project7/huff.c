#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define buf_SZ 100
#define N 256
struct node {
	char data;
	int freq;
	struct node*left;
	struct node*right;
};
struct node **heap;	//동적공간할당을 하기위해
int last = 0;	//heap이 어디까지 찼는지
char c_buf[100];
int b_idx = -1;
int Freq[N];
char *code[N];

void encoding(char *f_n);
void decoding(char *f_n);
void travel(struct node*cur, char data);
void addToHeap(struct node*temp);
struct node*delHeap();
int count();

void encoding(char *f_n) {	//.txt->.encoded
	char buf[buf_SZ];
	FILE *fp = fopen(f_n, "rt");
	if (fp == 0) return;
	memset(Freq, 0, N * sizeof(int));
	while (fgets(buf, buf_SZ, fp) != 0)	//file을 읽어옴
	{
		int len = strlen(buf);
		for (int i = 0; i < len; i++)
		{
			Freq[(int)buf[i]]++;
		}
	}

	int cnt = count();	//빈도수가 1이상인 것을 셈
	heap = (struct node**)malloc((cnt + 1) * sizeof(struct node*));
	memset(heap, 0, (cnt + 1) * sizeof(struct node*));

	for (int i = 0; i < N; i++)
	{
		if (Freq[i] > 0)
		{
			struct node*temp = (struct node*)malloc(sizeof(struct node));
			temp->data = (char)i;
			temp->freq = Freq[i];
			temp->left = temp->right = 0;
			addToHeap(temp);
		}
	}

	//huffman tree 구현
	struct node*first = 0;
	struct node*second = 0;
	while (1)
	{
		first = delHeap();
		second = delHeap();
		if (second == 0) break;
		struct node*new = (struct node*)malloc(sizeof(struct node)); //노드끼리 합칠려고 새로운 노드를 만듦
		new->data = 0;
		new->freq = first->freq + second->freq;
		new->left = first;
		new->right = second;
		addToHeap(new);
	}
	memset(code, 0, sizeof(code));	//code배열 초기화
	travel(first->left, '0');
	travel(first->right, '1');

	int num_code = 0;
	for (int i = 0; i < N; i++)
	{
		if (code[i] != 0)
		{
			num_code++;
			printf("%c : %s\n", (char)i, code[i]);
		}
	}

	FILE *fout = 0;	//huffman tree 저장
	fout = fopen("string.bin", "wb");
	if (fout != 0)
	{
		fwrite(&num_code, sizeof(num_code), 1, fout); //전제 ASCII개수
		char writebuf[100];
		for (int i = 0; i < N; i++)
		{
			if (code[i] != 0)
			{
				writebuf[0] = (char)i;
				writebuf[1] = (char)strlen(code[i]);
				strcpy(&writebuf[2], code[i]);	//huffman code 복사
				fwrite(writebuf, sizeof(char), 2 + strlen(code[i]), fout);
			}
		}
		FILE *fp = fopen(f_n, "rt");	//전체비트개수기록
		if (fp != 0)
		{
			int bit;
			bit = ftell(fout);
			if (fseek(fout, 4, SEEK_CUR) != 0) return;
			char bitbuf[buf_SZ];	//생성되는 비트스트림 저장할 버퍼
			int bitb_idx = 0;	//현재 비트스트림을 저장할 위치
			int bitshift = 7;	//비트쉬프트 횟수
			int bitnum = 0;

			memset(bitbuf, 0, buf_SZ);	//쓰레기값 방지
			while (fgets(buf, buf_SZ, fp) != 0)
			{
				int len = strlen(buf);
				for (int i = 0; i < len; i++)
				{
					char *h_code = code[(int)buf[i]];
					for (int j = 0; j < strlen(h_code); j++)
					{
						char val = 0;
						if (h_code[j] == '0') val = 0;
						else if (h_code[j] == '1') val = 1;
						val = val << bitshift;	//올바른 위치에 넣기 위해 shift
						bitshift--;
						bitbuf[bitb_idx] |= val; //ORmasking으로 data을 유지하며 data추가
						bitnum++;
						if (bitshift < 0)
						{
							bitshift = 7;
							bitb_idx++;
							if (bitb_idx >= buf_SZ)
							{
								fwrite(bitbuf, 1, buf_SZ, fout);
								bitb_idx = 0;
								memset(bitbuf, 0, buf_SZ);
							}
						}
					}
				}
			}
			if (bitbuf>0) fwrite(bitbuf, 1, bitb_idx + 1, fout);
			if (fseek(fout, bit, SEEK_SET) == 0) fwrite(&bitnum, sizeof(bitnum), 1, fout);
		}
	}
	else return 0;
}

void decoding(char *f_n) {
	FILE *fp = 0;
	fp = fopen(f_n, "rb");
	if (fp != 0)
	{
		int num = 0;
		fread(&num, sizeof(int), 1, fp);

		struct node *root = (struct node*)malloc(sizeof(struct node));
		root->left = root->right = 0;
		struct node*temp = root;
		for (int i = 0; i < num; i++) // huffman tree 복구
		{
			char ar[2]; //0은 문자, 1은 길이
			fread(ar, 2, 1, fp);
			char buf[100];
			fread(buf, 1, (int)ar[1], fp);	//huffman code 읽어옴
			buf[(int)ar[1]] = 0;
			printf("%c : %s\n", ar[0], buf);
			temp = root;
			for (int i = 0; i < (int)ar[1]; i++)
			{
				if (buf[i] == '0')
				{
					if (temp->left == 0)
					{
						temp->left = (struct node*)malloc(sizeof(struct node));
						temp->left->left = 0;
						temp->left->right = 0;
					}temp = temp->left;
				}
				else if (buf[i] == '1')
				{
					if (temp->right == 0)
					{
						temp->right = (struct node*)malloc(sizeof(struct node));
						temp->right->left = 0;
						temp->right->right = 0;
					}temp = temp->right;
				}
				else exit(0);
			}
			temp->data = ar[0];
		}

		int num_read = 0;
		fread(&num_read, sizeof(int), 1, fp);
		temp = root;
		char buf[buf_SZ];
		while (1)
		{
			int sz = fread(buf, 1, buf_SZ, fp);
			if (sz == 0) break;
			else
			{
				for (int i = 0; i < sz; i++)
				{
					for (int j = 0; j < 8; j++)	//8bit
					{
						if ((char)(buf[i] & 0x80) == 0) temp = temp->left;
						else temp = temp->right;
						buf[i] = buf[i] << 1;
						num_read--;
						if (temp->left == 0 && temp->right == 0)
						{
							printf("%c", temp->data);
							temp = root;
						}
						if (num_read == 0) return;
					}
				}
			}
		}
	}
	else return;
}

void travel(struct node*cur, char data) {	//테이블만들기
	b_idx++;
	c_buf[b_idx] = data;
	c_buf[b_idx + 1] = 0;
	if (cur->left == 0 && cur->right == 0) //더이상 내려갈 곳이 없음
	{
		char *h_code = (char *)malloc(strlen(c_buf) + 1);
		strcpy(h_code, c_buf);
		code[(int)cur->data] = h_code;
	}
	else
	{
		travel(cur->left, '0');
		travel(cur->right, '1');
	}
	c_buf[b_idx] = 0;
	b_idx--;
	return;
}

void addToHeap(struct node*temp) {
	last++;
	heap[last] = temp;
	int c_idx = last;
	int p_idx = c_idx / 2;
	while (p_idx >= 1)	//오름차순으로 정렬
	{
		if (heap[p_idx]->freq > heap[c_idx]->freq)
		{	//바꿔야함
			struct node *temp = heap[p_idx];
			heap[p_idx] = heap[c_idx];
			heap[c_idx] = temp;
			c_idx = p_idx;
			p_idx = c_idx / 2;
		}
		else break;
	}
}

struct node*delHeap() {	//Heap의 root를 꺼냄
	if (last <= 0) return 0;
	struct node*r_value = heap[1];
	heap[1] = heap[last];
	last--;
	int parent = 1;
	int left = 2 * parent;
	int right = left + 1;

	while (1)
	{
		if (left > last) break;	//자식 없음
		else if (right > last)	//왼쪽 자식만 있음
		{
			if (heap[left]->freq < heap[parent]->freq)
			{
				struct node*temp = heap[left];
				heap[left] = heap[parent];
				heap[parent] = temp;
				parent = left;
				left = 2 * parent;
				right = left + 1;
			}
			else break;
		}
		else //둘다 있을 경우
		{
			int min;	//작은 노드를 찾음
			if (heap[left]->freq <= heap[right]->freq) min = left;
			else min = right;
			if (heap[min]->freq < heap[parent]->freq)
			{
				struct node*temp = heap[min];
				heap[min] = heap[parent];
				heap[parent] = temp;
				parent = min;
				left = 2 * parent;
				right = left + 1;
			}
			else break;
		}
	}
	return r_value;
}

int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (Freq[i] > 0) cnt++;
	}return cnt;
}

int main(int cnt, char *data[]) {
	encoding(data[1]);
	//decoding(data[1]); //string.bin으로 입력받음
	return 0;
}