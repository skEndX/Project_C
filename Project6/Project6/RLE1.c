//#include<stdio.h>
//#define N 256*256
//unsigned char results[N] = { '\0' };	//encoding�� �����͸� ������ �迭�� ���������� ����
//
//int encoding(unsigned char num[N]) {
//	int i, cnt = 1, idx = 0;
//
//	printf("���ڵ� �� : ");
//	for (i = 0; i < N; i++)
//	{
//		if (num[i] == 0)	//�迭�� �����Ͱ� ������ �ݺ��� Ż��
//		{
//			printf("\n Finish\n");
//			break;
//		}
//		if ((num[i] != num[i + 1]) || (cnt == 255))	//���� ������ �����Ϳ� �ٸ��ų� �ݺ�Ƚ���� 255�� �Ǹ� �� �迭�� �ݺ�Ƚ���� �����͸� ����
//		{
//			results[idx] = cnt;
//			results[idx + 1] = num[i];	//�����ʹ� ����ĭ�� �����ؾ��ϹǷ� idx+1
//			cnt = 1;	//cnt�� �ٽ� 1�� �ʱ�ȭ
//			printf("%d%c", results[idx], results[idx + 1]);
//			idx += 2;	//�ݺ�Ƚ���� �����͸� 2ĭ�� �����ϱ� ������ 2�� ����
//		}
//		else
//		{
//			cnt++;
//		}
//	}return;
//}
//
//int decoding(unsigned char en_number[N]) {
//	int i, j, idx = 0;
//	unsigned char de_number[2 * N] = { 0, };
//	for (i = 0;; i += 2)
//	{
//		if (en_number[i] == 0)
//		{
//			break;
//		}
//		for (j = 0; j < en_number[i]; j++)	//�ݺ�Ƚ����ŭ �� �迭�� �����͸� �����ؾ��ϹǷ� j�� en_number[i]���� �ݺ�
//		{
//			printf("%c", en_number[i + 1]);
//			de_number[idx] = en_number[i + 1];
//			idx++;
//		}
//	}
//	printf("\n���ڵ� ��� : %s\n", de_number);
//}
//
//int main() {
//	unsigned char num[N] = { '1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1','1','1','1','1','1',
//		'1','1','1','1','1','1','1','1','1' ,'1' ,'1' ,
//	   '1' ,'1' ,'1' ,'1' ,'1' ,'1', '0','0',
//	   '1','1','1','1','1','1','0','0',      0 };
//	printf("���ڵ� �� : %s\n", num);
//	encoding(num);
//	printf("���ڵ� ���� : ");
//	decoding(results);
//	return 0;
//}