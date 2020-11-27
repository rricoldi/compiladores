%{

#include <stdio.h>
#include <ast.h>
extern int yylex();
extern char* yytext;
void yyerror(char *s);

TreeNode* AST = NULL;

%}

%union{
    TreeNode* ast;
    int integer;
}

/* declare tokens */
%token NUMBER
%token ADD
%token SUB
%token MUL
%token DIV
%token EOL

%type <ast> calc
%type <ast> exp
%type <ast> factor
%type <ast> term
%type <integer> NUMBER

%start calc

%%

calc: exp EOL { AST = $1; 
                    if(AST)
                    {
                        RPN_Walk(AST);
                        Delete_Tree(AST);
                    }
                    else
                    {
                        printf("AST is NULL\n");
                    }
                    return 0;
                }
;

exp: factor          { $$ = $1;}
    | exp ADD factor {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                       aux->node_type = ADD;
                       aux->value = 0;
                       aux->left = $1;
                       aux->right = $3;
                       $$ = aux;
                      }
    | exp SUB factor {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                       aux->node_type = SUB;
                       aux->value = 0;
                       aux->left = $1;
                       aux->right = $3;
                       $$ = aux;
                      }
;

factor: term          { $$ = $1;}
    | factor MUL term {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                       aux->node_type = MUL;
                       aux->value = 0;
                       aux->left = $1;
                       aux->right = $3;
                       $$ = aux;
                      }
    | factor DIV term {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                       aux->node_type = DIV;
                       aux->value = 0;
                       aux->left = $1;
                       aux->right = $3;
                       $$ = aux;
                      }
;

term: NUMBER   { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node)); 
                 aux->node_type = NUMBER;
                 aux->value = $1;
                 aux->left = NULL;
                 aux->right = NULL;
                 $$ = (TreeNode*) aux;
               }
;

%%

void yyerror(char *s)
{
    printf("Erro de Sintaxe: %s", yytext);
    exit(0);
}

int main(int argc, char **argv)
{
    return yyparse();
}
