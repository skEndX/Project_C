#include<stdio.h>
#define N 10

void change(char(*str)[100]) { //100ĭ�� �ǳʶٴ� �迭�� �����͸� ����
	char temp[N][100] = { 0 }; //���ڿ��� �ٲ� ��, �ӽ÷� ������ �迭

	for (int i = 0; i < N/2; i++)
		for (int j = 0; j < 100; j++) {
			temp[i][j] = str[i][j];	//�迭�� ������ ���� str�� temp�� �����Ͽ� �ӽ� ����
			str[i][j] = str[N - 1 - i][j]; //������ �ٲ���ϴ� str�� ����
			str[N - 1 - i][j] = temp[i][j]; //�ӽ÷� �����صξ��� temp�� �迭�� ������ ���� str�� ����
		}
}

int main() {
	char str[N][100] = { "abc","123","������","xyz","def","456","�󸶹�","ilk","201801730","�����" };

	change(str);

	for (int i = 0; i < N; i++)
		printf("%s ", str[i]);

	return 0;
}
