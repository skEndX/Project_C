//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct node {
//	struct node *left;
//	struct node*right;
//	char *name;
//	char *phone;
//};
//struct node*root = 0;
//
//struct node*createNewNode(char *name, char *phone) {
//	char *_name, *_phone;
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	new->left = new->right = 0;
//
//	_name = (char *)malloc(strlen(name) + 1);
//	strcpy(_name, name);
//
//	_phone = (char *)malloc(strlen(phone) + 1);
//	strcpy(_phone, phone);
//
//	new->name = _name;
//	new->phone = _phone;
//	return new;
//}
//
//void addToBST(char *name, char *phone) {
//	struct node*new = createNewNode(name, phone);
//	struct node*temp = root;
//	if (root==0)
//	{
//		root = new;
//		return;
//	}
//	while (1)
//	{	//strcmp(s1,s2) -> return 0 s1==s2 -> return -1 s1<s2 -> return 1 s1>s2
//		if (strcmp(temp->name,new->name)<0)	//right
//		{
//			if (temp->right==0)
//			{
//				temp->right = new;
//				return;
//			}
//			temp = temp->right;
//		}
//		else if (strcmp(temp->name,new->name)>0) //left
//		{
//			if (temp->left==0)
//			{
//				temp->left = new;
//				return;
//			}
//			temp = temp->left;
//		}
//		else return;	//µ¿ÀÏ Ãß°¡ÇÏÁö ¾ÊÀ½
//	}
//}
//
//void inorder(struct node *node) {
//	if (node == 0) return;
//	inorder(node->left);
//	printf("name : %s	phone : %s\n", node->name, node->phone);
//	inorder(node->right);
//}
//
//void searchBST(char *name) {
//	struct node*temp = root;
//	while (1)
//	{
//		if (temp == 0) return;
//		if (strcmp(temp->name, name) < 0)	//right
//		{
//			temp = temp->right;
//		}
//		else if (strcmp(temp->name, temp) > 0) //left
//		{
//			temp = temp->left;
//		}
//		else
//		{
//			printf("%sÀÇ ¹øÈ£ : %s\n", name, temp->phone);
//			return;
//		}
//	}
//}
//
//int main() {
//	char buf[30];
//	addToBST("¹ÚÃ¶¼ö", "001");
//	addToBST("±è¿µÈñ", "002");
//	addToBST("±è´ÙÈñ", "003");
//
//	inorder(root);
//
//	printf("ÀÌ¸§ : ");
//	gets(buf);
//	searchBST(buf);
//	return 0;
//}