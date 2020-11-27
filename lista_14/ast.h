#include <stdio.h>
#include <stdlib.h>

typedef struct node TreeNode;
struct node
{
	int node_type;
	int value;
	TreeNode* left;
	TreeNode* right;
};

void RPN_Walk(TreeNode* aux);
void Delete_Tree(TreeNode* aux);
