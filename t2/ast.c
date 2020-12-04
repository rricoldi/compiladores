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

float absolute(float value) {
	if(value < 0)
		return -value;
	return value;
}

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
			case ABS: { stack[stackCount-1] = absolute(stack[stackCount-1]); break; }
			case NUM_INTEGER: { stack[stackCount] = aux->value; stackCount++; };break;
			case NUM_REAL: { stack[stackCount] = aux->value; stackCount++; };break;
			case VARIABLE: { stack[stackCount] = var; stackCount++; };break;
			case L_PAREN: break;
			default: break;
		}
	}
}

float calculate(TreeNode* aux, float var) {
	stackCount = 0;
	calculateAux(aux, var);

	return stack[0];
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
	}

	return result;
}

float plot(TreeNode* aux, Settings* settings) {
	char display[25][80];
	int i, j;
	float k;
	float result;
	int xDisplay = 0, yDisplay;

	for(i=0; i < 25; i++) {
		for(j=0; j < 80; j++) {
			display[i][j] = ' ';
		}
	}

	if(settings->draw_axis) {
		for(i=0; i < 25; i++) {
			display[i][40] = '|';
		}

		for(j=0; j < 80; j++) {
			display[12][j] = '-';
		}
		display[12][40] = '*';
	}

	for(k = settings->h_view_lo; k< settings->h_view_hi; k = k + ((settings->h_view_hi + absolute(settings->h_view_lo)) / 80)) {
		if(xDisplay >= 80)
			break;

		result = calculate(aux, k);
		
		yDisplay = 12 - round(result/((settings->v_view_hi + absolute(settings->v_view_lo)) / 25));

		if(yDisplay < 0 || yDisplay > 24) {
			xDisplay ++;
			continue;
		}

		display[yDisplay][xDisplay] = '*';
		xDisplay++;
	}

	for(i=0; i < 25; i++) {
		for(j=0; j < 80; j++) {
			printf("%c", display[i][j]);
		}
	}	
}

float matrixX[10][10];
int wMatrix, hMatrix;

int createMatrix(TreeNode* MATRIX) {
	wMatrix=1;
	hMatrix=1;
	int i, j;
	TreeNode *aux, *aux2;

    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            matrixX[i][j] = 0.0;
        }
    }

	i = 0; j = 0;

	aux = MATRIX;
	while(aux != NULL) {
		if(i >= 10) {
			return 1;
		}
		if(hMatrix < i+1){
			hMatrix = i+1;
		}
		matrixX[i][j] = aux->value;
		aux2 = aux->left;
		while(aux2 != NULL) {
			j++;
			if(j >= 10) {
				return 1;
			}
			matrixX[i][j] = aux2->value;
			if(wMatrix < j+1){
				wMatrix = j+1;
			}
			aux2 = aux2->right;
		}
		j = 0;
		i++;
		aux = aux->right;
	}
	return 0;
}


void showMatrix() {
	int i, j, aumento = 0;

	int vetorAumentos[wMatrix];
	for(i = 0; i < wMatrix; i++) {
		vetorAumentos[i] = 0;
	}

	i =0; j = 0;
	while(i < wMatrix) {
		while(j < hMatrix) {
			if(matrixX[j][i] < 0) {
				aumento ++;
				vetorAumentos[i] = 1;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}

	printf("\n+-");
	for(i = 0; i <wMatrix*13+aumento; i++) {
		printf(" ");
	}
	printf(" -+\n");

	for(i=0;i<hMatrix;i++) {
		printf("|  ");
		for(j=0;j<wMatrix;j++) {
			if(matrixX[i][j] < 0) {
				printf("%.6e ", matrixX[i][j]);
			} else {
				if(vetorAumentos[j] > 0) {
					printf(" %.6e ", matrixX[i][j]);
				} else {
					printf("%.6e ", matrixX[i][j]);
				}
			}

		}
		printf(" |\n");
	}

	printf("+-");
	for(i = 0; i <wMatrix*13+aumento; i++) {
		printf(" ");
	}
	printf(" -+\n\n");
}

float Laplace(int tamanho, float matriz[tamanho][tamanho]) {
	if(tamanho == 1) {
		return matriz[0][0];
	} else {
		float determinant = 0.0;
		float fator;
		int i, j, k, l, m;
        
        for(i = 0; i < tamanho; i++){
            if (matriz[0][i] != 0) {
                float aux[tamanho - 1][tamanho - 1];
                k = 0, j = 0;            
                for(l = 1; l < tamanho; l++){
                    for(m = 0; m < tamanho; m++){
                        if(m != i){
                            aux[k][j] = matriz[l][m];
                            j++;
                        }
                    }
                    k++;
                    j = 0;
                }
				if(i % 2 == 0) {
					fator = matriz[0][i];
				} else {
					fator = -matriz[0][i];
				}
                determinant = determinant + fator * Laplace(tamanho - 1, aux);
            }
        }
		return determinant;
	}
}

int solveDeterminant() {
	if(wMatrix != hMatrix) {
		return 1;
	}

	float matriz[wMatrix][wMatrix];
	int i, j;
	for(i=0;i<wMatrix;i++) {
        for(j=0;j<wMatrix;j++) {
            matriz[i][j] = matrixX[i][j];
        }
    }

	printf("\n%.6f\n\n", Laplace(wMatrix, matriz));

	return 0;
}

void LU(float matriz[hMatrix][wMatrix]) {

    float u[hMatrix][hMatrix];
    int n = hMatrix;
    float l[hMatrix][hMatrix];
    int i, j, k;

    float values[hMatrix];
	float divisions[hMatrix];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            u[i][j] = matriz[i][j];
            if(i == j) {
                l[i][j] = 1;
            } else {
                l[i][j] = 0;
            }
        }
    }

    for (j = 0; j < n-1; j++) {
        for(i=j+1; i < n; i++) {
            l[i][j] = u[i][j]/u[j][j];
            for(k=j+1; k < n; k++) {
                u[i][k] = u[i][k] - l[i][j]*u[j][k];
            }
            u[i][j] = 0;
        }
    }

	for(i=0; i < n; i++) {
        for(j=i+1; j < n; j++) {
            for(k= 0; k < n; k++) {
                if(fmod(matriz[i][k], matriz[j][k]) != 0 && fmod(matriz[j][k], matriz[i][k]) != 0) {
                    break;
                }
                if(matriz[i][k] > matriz[j][k]) {
                    divisions[k] = matriz[i][k]/matriz[j][k];
                } else {
                    divisions[k] = matriz[j][k]/matriz[i][k];
                }
            }

            for(k= 0; k < n; k++) {

                if(divisions[k] != divisions[0]) {
                    break;
                }
                if(k == n-1 && (matriz[i][n]/divisions[0] == matriz[j][n] || matriz[j][n]/divisions[0] == matriz[i][n])) {
                    printf("\nSPI - The Linear System has infinitely many solutions\n\n");
                    return;
                } else if(k == n-1 && (matriz[i][n]/divisions[0] != matriz[j][n] && matriz[j][n]/divisions[0] != matriz[i][n])) {
                    printf("\nSI - The Linear System has no solution\n\n");
                    return;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
       values[i] = 5532;
    }

    for(i=0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(l[i][j] == 0) {
                continue;
            }

            if(values[j] != 5532) {
                matriz[i][3] -= l[i][j]*values[j];
            } else {
                values[i] = matriz[i][3]/l[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
       values[i] = 5532;
    }

    for(i=n-1; i >=0; i--) {
        for (j = n-1; j >= 0; j--) {
            if(u[i][j] == 0) {
                continue;
            }

            if(values[j] != 5532) {
                matriz[i][3] -= u[i][j]*values[j];
            } else {
                values[i] = matriz[i][3]/u[i][j];
            }
        }
    }

	printf("\nMatrix x:\n\n");
    
    for (i = 0; i < n; i++) {
        printf("%.6f\n", values[i]);
    }
	printf("\n");
}

int solveLinearSystem() {
	if(wMatrix-1 != hMatrix) {
		return 1;
	}

	float matriz[hMatrix][wMatrix];
	int i, j;
	for(i=0;i<hMatrix;i++) {
        for(j=0;j<wMatrix;j++) {
            matriz[i][j] = matrixX[i][j];
        }
    }

	LU(matriz);

	return 0;
}

