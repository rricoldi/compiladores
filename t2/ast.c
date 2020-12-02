#include <ast.h>
#include <sintatico.tab.h>

TreeNode* createNode(int node_type, float value, TreeNode* left, TreeNode* right) {
	TreeNode* aux = (TreeNode*)malloc(sizeof(struct node)); 
	aux->node_type = node_type;
	aux->value = value;
	aux->left = left;
	aux->right = right;	

	return aux;
}

void RPN_Walk(TreeNode* aux) {
	if(aux)
	{
		RPN_Walk(aux->left);
		RPN_Walk(aux->right);
		switch(aux->node_type)
		{
			case PLUS:{printf("+ ");};break;
			case MINUS:{printf("- ");};break;
			case MULTIPLY:{printf("* ");};break;
			case DIV:{printf("/ ");};break;
			case POWER:{printf("^ ");};break;
			case REMAINDER:{printf("%% ");};break;
			case SEN:{printf("SEN ");};break;
			case COS:{printf("COS ");};break;
			case TAN:{printf("TAN ");};break;
			case ABS:{printf("ABS ");};break;
			case NUM_INTEGER:{printf("%.6f ",aux->value);};break;
			case NUM_REAL:{printf("%.6f ",aux->value);};break;
			case VARIABLE:{printf("x ");};break;
			case L_PAREN: break;
			default:{printf("ERROR: INVALID TYPE ");};break;
		}
	}
}

void Delete_Tree(TreeNode* aux) {
    if(aux)
    {
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}