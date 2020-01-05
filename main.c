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
TreeNode searchTree(TreeNode *top,int Data)
{
	if (top->data==Data)
		return *top;
	else if (top->data>Data)
		return searchTree(top->left, Data);
	else
		return searchTree(top->right, Data);
}
void showTree(TreeNode top)
{
	printf("%d ", top.data);
	if (top.left==NULL)
		printf("%d ", 0);
	else
		printf("%d ", top.left->data);
	if (top.right==NULL)
		printf("%d\n", 0);
	else
		printf("%d\n", top.right->data);
}

int main(int argc, char *argv[]) 
{
	char str[7];
	TreeNode *Tree;
	int MAX=0;
	while (fgets(str, sizeof(str), stdin))
	{
		int input=atoi(str);
		if (input>MAX)
			MAX = input;
		if(Tree==NULL)
		{
			Tree = (TreeNode *)malloc(sizeof(TreeNode));
			Tree->data = input;
		}
		else
			SetTree(Tree, input);
	}
	for (size_t i = 0; i < MAX; i++)
	{
		showTree(searchTree(Tree,i+1));
	}
	return 0;
}
