////binary search�� ���(�ð����⵵)�� log2(n) �����ϸ� nlog2(n), �������� n
////binary tree : �ϳ��� ��忡�� �ִ� 2�� link
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
//	if (root==0)	//bst�� ������� ���
//	{
//		root = new;
//		return;
//	}
//
//	while (1)
//	{
//		//bst�� �Ⱥ�������� temp->data�� new->data�� ��
//		if (new->data < temp->data)
//		{	//�������� ������
//			if (temp->left == 0)	//���ڸ��� ����
//			{
//				temp->left = new;
//				return;
//			}
//			else	//�ڸ� ����
//			{
//				temp = temp->left;
//			}
//		}
//		else	//new->data>temp->data
//		{	//���������� ������
//			if (temp->right == 0)	//���ڸ��� ����
//			{
//				temp->right = new;
//				return;
//			}
//			else	//�ڸ� ����
//			{
//				temp = temp->right;
//			}
//		}
//	}
//}
//
//int searchbst(int _data) {	//_data�� ���� ���� ��� ������ 1�� ��ȯ, �ƴ϶�� 0�� ��ȯ
//	struct node*temp = root;
//	while (1)
//	{
//		if (temp==0)
//		{
//			return 0;	//�� ã��
//		}
//		if (temp->data==_data)
//		{
//			return 1;	//ã��
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