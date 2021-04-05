////binary search의 빅오(시간복잡도)는 log2(n) 정렬하면 nlog2(n), 무작위는 n
////binary tree : 하나의 노드에서 최대 2개 link
//
//#include<stdio.h>
//#include<stdlib.h>
//struct node {
//	int data;
//	struct node*left;
//	struct node*right;
//};
//struct node*root = 0;
//
//struct node*createbstnode(int _data) {
//	struct node*temp = (struct node*)malloc(sizeof(struct node));
//	temp->data = _data;
//	temp->left = temp->right = 0;
//	return temp;
//}
//
//void addtobst(int _data) {
//	struct node*new = createbstnode(_data);
//	struct node*temp = root;
//
//	if (root==0)	//bst가 비어있을 경우
//	{
//		root = new;
//		return;
//	}
//
//	while (1)
//	{
//		//bst가 안비어있으면 temp->data와 new->data를 비교
//		if (new->data < temp->data)
//		{	//왼쪽으로 내려감
//			if (temp->left == 0)	//빈자리가 있음
//			{
//				temp->left = new;
//				return;
//			}
//			else	//자리 없음
//			{
//				temp = temp->left;
//			}
//		}
//		else	//new->data>temp->data
//		{	//오른쪽으로 내려감
//			if (temp->right == 0)	//빈자리가 있음
//			{
//				temp->right = new;
//				return;
//			}
//			else	//자리 없음
//			{
//				temp = temp->right;
//			}
//		}
//	}
//}
//
//int searchbst(int _data) {	//_data의 값을 가진 노즈가 있으면 1을 반환, 아니라면 0을 반환
//	struct node*temp = root;
//	while (1)
//	{
//		if (temp==0)
//		{
//			return 0;	//못 찾음
//		}
//		if (temp->data==_data)
//		{
//			return 1;	//찾음
//		}
//		if (_data<temp->data)
//		{
//			temp = temp->left;
//		}
//		else
//		{
//			temp = temp->right;
//		}
//	}
//}
//
//int main() {
//	addtobst(10);
//	addtobst(5);
//	addtobst(20);
//	addtobst(30);
//
//	searchbst(20);
//	searchbst(17);
//	//showall
//	return;
//}