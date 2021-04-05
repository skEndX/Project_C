#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*left;
	struct node*right;
};
struct node*root = 0;

void addToBST(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->left = new->right = 0;
	struct node*temp = root;
	if (root==0)
	{
		root = new;
		return;
	}
	while (1)
	{
		if (new->data<temp->data)
		{
			if (temp->left==0)
			{
				temp->left = new;
				return;
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right==0)
			{
				temp->right = new;
				return;
			}
			temp = temp->right;
		}
	}
}

struct node *delBST(struct node*node, int _data) {
	if (node == 0) return;
	if (_data==node->data)
	{
		if (node->left==0&&node->right==0)
		{
			free(node);
			return 0;
		}
		else if (node->left==0)
		{
			struct node*temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right==0)
		{
			struct node*temp = node->left;
			free(node);
			return temp;
		}
		else
		{
			struct node*temp = node->right;
			while (temp->left!=0)
			{
				temp = temp->left;
			}
			node->data = temp->data;
			node->right=delBST(node->right, temp->data);
			return node;
		}
	}
	else if (_data<node->data)
	{
		node->left=delBST(node->left, _data);
		return node;
	}
	else
	{
		node->right=delBST(node->right, _data);
		return node;
	}
}

void inorder(struct node*node) {
	if (node == 0) return;
	inorder(node->left);
	printf("%d\n", node->data);
	inorder(node->right);
}

int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToBST(data);
	}
	inorder(root);

	scanf("%d", &data);
	delBST(root, data);
	printf("\n");
	inorder(root);
	return 0;
}