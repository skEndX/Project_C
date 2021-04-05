#include<stdio.h>
#define N 10

void change(char(*str)[100]) { //100칸씩 건너뛰는 배열의 포인터를 만듦
	char temp[N][100] = { 0 }; //문자열을 바꿀 때, 임시로 저장할 배열

	for (int i = 0; i < N/2; i++)
		for (int j = 0; j < 100; j++) {
			temp[i][j] = str[i][j];	//배열의 순서가 앞인 str을 temp에 복사하여 임시 저장
			str[i][j] = str[N - 1 - i][j]; //순서를 바꿔야하는 str을 복사
			str[N - 1 - i][j] = temp[i][j]; //임시로 저장해두었던 temp를 배열의 순서가 뒤인 str에 복사
		}
}

int main() {
	char str[N][100] = { "abc","123","가나다","xyz","def","456","라마바","ilk","201801730","김다희" };

	change(str);

	for (int i = 0; i < N; i++)
		printf("%s ", str[i]);

	return 0;
}
