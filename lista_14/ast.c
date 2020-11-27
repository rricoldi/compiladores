#include <ast.h>
#include <sintatico.tab.h>

float number1 = 0.0;
float number2 = 0.0;
float number3 = 0.0;

void RPN_Walk(TreeNode* aux)
{
	if(aux)
	{
		RPN_Walk(aux->left);
		RPN_Walk(aux->right);
		switch(aux->node_type)
		{
			case ADD:{};break;
			case SUB:{};break;
			case MUL:{};break;
			case DIV:{};break;
			case NUMBER:{};break;
			default:{printf("ERROR: INVALID TYPE ");};break;
		}
	}
}

void CalculaExpressao(TreeNode* aux)
{
	if(aux)
	{
		CalculaExpressao(aux->left);
		CalculaExpressao(aux->right);
		switch(aux->node_type)
		{
			case ADD:{number3 = number2 + number3; number2 = number1; number1 = 0;};break;
			case SUB:{number3 = number2 - number3; number2 = number1; number1 = 0;};break;
			case MUL:{number3 = number2 * number3; number2 = number1; number1 = 0;};break;
			case DIV:{number3 = number2 / number3; number2 = number1; number1 = 0;};break;
			case NUMBER:{number1 = number2; number2 = number3; number3 = aux->value;};break;
			default:{printf("ERROR: INVALID TYPE ");};break;
		}
	}
	printf("\nresultado = %.2f", number3);
}

void Delete_Tree(TreeNode* aux)
{
    if(aux)
    {
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}