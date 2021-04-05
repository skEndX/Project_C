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
struct node **heap;	//���������Ҵ��� �ϱ�����
int last = 0;	//heap�� ������ á����
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
	while (fgets(buf, buf_SZ, fp) != 0)	//file�� �о��
	{
		int len = strlen(buf);
		for (int i = 0; i < len; i++)
		{
			Freq[(int)buf[i]]++;
		}
	}

	int cnt = count();	//�󵵼��� 1�̻��� ���� ��
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

	//huffman tree ����
	struct node*first = 0;
	struct node*second = 0;
	while (1)
	{
		first = delHeap();
		second = delHeap();
		if (second == 0) break;
		struct node*new = (struct node*)malloc(sizeof(struct node)); //��峢�� ��ĥ���� ���ο� ��带 ����
		new->data = 0;
		new->freq = first->freq + second->freq;
		new->left = first;
		new->right = second;
		addToHeap(new);
	}
	memset(code, 0, sizeof(code));	//code�迭 �ʱ�ȭ
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

	FILE *fout = 0;	//huffman tree ����
	fout = fopen("string.bin", "wb");
	if (fout != 0)
	{
		fwrite(&num_code, sizeof(num_code), 1, fout); //���� ASCII����
		char writebuf[100];
		for (int i = 0; i < N; i++)
		{
			if (code[i] != 0)
			{
				writebuf[0] = (char)i;
				writebuf[1] = (char)strlen(code[i]);
				strcpy(&writebuf[2], code[i]);	//huffman code ����
				fwrite(writebuf, sizeof(char), 2 + strlen(code[i]), fout);
			}
		}
		FILE *fp = fopen(f_n, "rt");	//��ü��Ʈ�������
		if (fp != 0)
		{
			int bit;
			bit = ftell(fout);
			if (fseek(fout, 4, SEEK_CUR) != 0) return;
			char bitbuf[buf_SZ];	//�����Ǵ� ��Ʈ��Ʈ�� ������ ����
			int bitb_idx = 0;	//���� ��Ʈ��Ʈ���� ������ ��ġ
			int bitshift = 7;	//��Ʈ����Ʈ Ƚ��
			int bitnum = 0;

			memset(bitbuf, 0, buf_SZ);	//�����Ⱚ ����
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
						val = val << bitshift;	//�ùٸ� ��ġ�� �ֱ� ���� shift
						bitshift--;
						bitbuf[bitb_idx] |= val; //ORmasking���� data�� �����ϸ� data�߰�
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
		for (int i = 0; i < num; i++) // huffman tree ����
		{
			char ar[2]; //0�� ����, 1�� ����
			fread(ar, 2, 1, fp);
			char buf[100];
			fread(buf, 1, (int)ar[1], fp);	//huffman code �о��
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

void travel(struct node*cur, char data) {	//���̺����
	b_idx++;
	c_buf[b_idx] = data;
	c_buf[b_idx + 1] = 0;
	if (cur->left == 0 && cur->right == 0) //���̻� ������ ���� ����
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
	while (p_idx >= 1)	//������������ ����
	{
		if (heap[p_idx]->freq > heap[c_idx]->freq)
		{	//�ٲ����
			struct node *temp = heap[p_idx];
			heap[p_idx] = heap[c_idx];
			heap[c_idx] = temp;
			c_idx = p_idx;
			p_idx = c_idx / 2;
		}
		else break;
	}
}

struct node*delHeap() {	//Heap�� root�� ����
	if (last <= 0) return 0;
	struct node*r_value = heap[1];
	heap[1] = heap[last];
	last--;
	int parent = 1;
	int left = 2 * parent;
	int right = left + 1;

	while (1)
	{
		if (left > last) break;	//�ڽ� ����
		else if (right > last)	//���� �ڽĸ� ����
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
		else //�Ѵ� ���� ���
		{
			int min;	//���� ��带 ã��
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
	//decoding(data[1]); //string.bin���� �Է¹���
	return 0;
}