#include<stdio.h>

#if 0
int main() {
	char sentence[2][3][20] = { "There are","were","bbbddd bb ad bbdd","e&e","afdf fsd","sfdfsfuf" };
	char data[6];8
	scanf("%s", &data[0]);

	int flag = 0, f_cnt = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int a = 0; a < strlen(sentence[i][j]); a++) //���ڿ��� ���̸�ŭ �ݺ�
			{
				if (sentence[i][j][a] == data[0])	//�Է� ���� �������� ù ��° ���ڿ� ���ڿ��� ���ڰ� ���ٸ�
				{
					for (int count = 0; count < strlen(data); count++) //�Է� ���� �����͸�ŭ �ݺ�
					{
						//*�ڸ��� � �����ڰ� �͵� �ǹǷ� count�� +1 (��, �������� ���� �ش�)
						if (data[count] == '*' && sentence[i][j][a + count] >= 'a' && sentence[i][j][a + count] <= 'z' || sentence[i][j][a + count] >= 'A' && sentence[i][j][a + count] <= 'Z') count++;
						if (sentence[i][j][a + count] == data[count]) flag = 1; //���ڰ� ���ٸ�
						else //�ٸ� ��� flag�� 0���� �ٲٰ� ���̻� ���� �ʿ䰡 ���� ������ �ݺ��� Ż��
						{
							flag = 0;
							break;
						}
					}
					if (flag == 1) f_cnt++; //���ڿ��� �����Ͱ� ���ԵǾ� �����Ƿ� +1
				}
			}
	flag = 0; //�ʱ�ȭ

	printf("sentence�迭 �� data�迭�� ���� : %d", f_cnt);
}

int main(void)
{
	char sentence[2][3][20] = { "There are","were","bbbddd bb ad bbdd","exe","afdf fsd","sfdfsfuf" };
	char data[6];
	scanf("%s", &data[0]);

	int cnt = 0, count;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < strlen(sentence[i][j]); k++)
			{
				count = k;
				for (int l = 0; l < strlen(data); l++)
				{
					if (data[l] == '*' && sentence[i][j][count] != ' ') count++;
					else if (sentence[i][j][count] == data[l])
					{
						count++;
						if (l == strlen(data) - 1)
						{
							cnt++;
							break;
						}
					}
					else break;
				}
			}

	printf("sentence�迭 �� data�迭�� ���� : %d", cnt);
}
#endif

#if 0
int main() {
	char data[2][2][2];
	printf("%d	%d	%d	%d\n", &data[0][0] + 1, &data[0][1] + 1, &data[1][0] + 1, &data[1][1] + 1);
	printf("%d	%d	%d	%d\n", &data[0][0], &data[1][0], &data[0][1], &data[1][1]);
	printf("%d	%d	%d	%d\n", data[0][0], data[1][0], data[0][1], data[1][1]);
	printf("%d	%d	%d	%d\n", data[0][0] + 1, data[0][1] + 1, data[1][0] + 1, data[1][1] + 1);
}
#endif

#if 0
int main() {
	char statement[2][2][100], record[62] = { 0, };
	int a, count;
	for (int i = 0; i < 4; i++)
		printf("Enter a statement %d\n: ", i); scanf("%s", &statement[0][0]+i);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (count = 0; count < 62; count++)
				for (a = 0; a < strlen(statement); a++)
				{
					if (statement[i][j][a] == (count + '0') && count >= 0 && count < 10) //����
						record[count]++;
					if (statement[i][j][a] == (count + 'A' - 10) && count >= 10 && count < 36) //�빮��
						record[count]++;
					if (statement[i][j][a] == (count + 'a' - 36) && count >= 36 && count < 62) //�ҹ���
						record[count]++;
				}

	//����, �빮��, �ҹ��� ������� �󵵼� ���
	for (count = 0; count < 10; count++) printf("\n%d: %d times", count, record[count]);
	for (count = 0; count < 26; count++) printf("\n%c: %d times", count + 'A', record[count + 10]);
	for (count = 0; count < 26; count++) printf("\n%c: %d times", count + 'a', record[count + 36]);
}
#endif