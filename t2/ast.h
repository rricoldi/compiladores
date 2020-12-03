#include <stdio.h>
#include <settings.h>
#include <stdlib.h>

typedef struct node TreeNode;
struct node
{
	int node_type;
	float value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createNode(int node_type, float value, TreeNode* left, TreeNode* right);
float calculate(TreeNode* aux, float var);
float integrate(float inf_lim, float sup_lim, TreeNode* aux, Settings* settings);
float plot(TreeNode* aux, Settings* settings);
void RPN_Walk(TreeNode* aux);
void Delete_Tree(TreeNode* aux);
