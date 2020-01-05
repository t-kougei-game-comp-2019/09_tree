#include <stdio.h>
#include <stdlib.h>
typedef struct _TreeNode
{
	struct _TreeNode *left;
	struct _TreeNode *right;
	int data;
}TreeNode;
void SetTree(TreeNode *Node,int data)
{
	if(Node->data>data)
	{
		if(Node->left==NULL)
		{
			Node->left=(TreeNode *)malloc(sizeof(TreeNode));
			Node->left->data = data;
		}
		else
		{
			SetTree(Node->left, data);
		}
	}
	else
	{
		if(Node->right==NULL)
		{
			Node->right=(TreeNode *)malloc(sizeof(TreeNode));
			Node->right->data = data;
		}
		else
		{
			SetTree(Node->right, data);
		}
	}
	
}
int main(int argc, char *argv[]) 
{
    char str[7];
	TreeNode *Tree;
	while (fgets(str, sizeof(str), stdin))
	{
		printf("%s", str);
		int input=atoi(str);
		if(Tree==NULL)
		{
			Tree = (TreeNode *)malloc(sizeof(TreeNode));
			Tree->data = input;
		}
	}

	return 0;
}
