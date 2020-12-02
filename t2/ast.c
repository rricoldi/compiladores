#include <ast.h>
#include <sintatico.tab.h>
#include <math.h>

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
			case ADD:
			case PLUS:{printf("+ ");};break;
			case SUB:
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

int stackCount;
float stack[1000];

void calculateAux(TreeNode* aux, float var) {
	if(aux)
	{
		calculateAux(aux->left, var);
		calculateAux(aux->right, var);
		switch(aux->node_type)
		{
			case ADD: { stack[stackCount-2] = stack[stackCount-2] + stack[stackCount-1]; stackCount--; break; }
			case PLUS: { stack[stackCount-1] = stack[stackCount-1]; break; }
			case SUB: { stack[stackCount-2] = stack[stackCount-2] - stack[stackCount-1]; stackCount--; break; }
			case MINUS: { stack[stackCount-1] = - stack[stackCount-1]; break; }
			case MULTIPLY: { stack[stackCount-2] = stack[stackCount-2] * stack[stackCount-1]; stackCount--; break; }
			case DIV: { stack[stackCount-2] = stack[stackCount-2] / stack[stackCount-1]; stackCount--; break; }
			case POWER: { stack[stackCount-2] = pow(stack[stackCount-2], stack[stackCount-1]); stackCount--; break; }
			case REMAINDER: { stack[stackCount-2] = (int) stack[stackCount-2] % (int) stack[stackCount-1]; stackCount--; break; }
			case SEN: { stack[stackCount-1] = sin(stack[stackCount-1]); break; }
			case COS: { stack[stackCount-1] = cos(stack[stackCount-1]); break; }
			case TAN: { stack[stackCount-1] = tan(stack[stackCount-1]); break; }
			case ABS: { stack[stackCount-1] = fabs(stack[stackCount-1]); break; }
			case NUM_INTEGER: { stack[stackCount] = aux->value; stackCount++; };break;
			case NUM_REAL: { stack[stackCount] = aux->value; stackCount++; };break;
			case VARIABLE: { stack[stackCount] = var; stackCount++; };break;
			case L_PAREN: break;
			default: break;
		}
		// int i;
		// for(i = 0; i < stackCount; i++) {
		// 	printf("%f ", stack[i]);
		// }
		// printf("\n");
	}
}

float calculate(TreeNode* aux, float var) {
	stackCount = 0;
	calculateAux(aux, var);

	return stack[0];

	// printf("Valor final: %.6f", stack[0]);
}

void Delete_Tree(TreeNode* aux) {
    if(aux)
    {
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}

float integrate(float inf_lim, float sup_lim, TreeNode* aux, Settings* settings) {
	int i;
	float result = 0;
	float delta = (sup_lim - inf_lim) / settings->integral_steps;

	for(i = 0; i < settings->integral_steps; i++) {
		result += delta * calculate(aux, inf_lim + (delta * i));
		// printf("\ni: %d xi: %f RESULT: %f\n", i, inf_lim + delta * i, result);
	}

	return result;
}