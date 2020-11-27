#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define tamanho_do_alfabeto 27
#define numero_de_tokens 9
#define numero_de_estados_finais 10

enum tipos_de_token {IF=1, THEN=2, ELSE=3, BEGIN=4, END=5, PRINT=6, SEMI=7, NUM=8, EQ=9, ERR=0, ENDOF=10, EOL=11};
char tokens_escritos[][6] = {"", "if", "then", "else", "begin", "end", "print", ";", "num", "="};
char alfabeto[] = { '+', '-', '=', ';', 'b', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'n', 'p', 'r', 's', 't', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int tokens[] = { ERR, ERR, ERR, NUM, ERR, IF, EQ, ERR, ERR, ERR, THEN, ERR, ERR, ERR, ELSE, SEMI, ERR, ERR, ERR, ERR, BEGIN, ERR, END, ERR, ERR, ERR, ERR, PRINT, NUM };
int estados_finais[] = { 3, 5, 6, 10, 14, 15, 20, 22, 27, 28 };

int edges[][tamanho_do_alfabeto] = {
    /*  symbols    +,   -,   =,   ;,   b,   d,   e,   f,   g,   h,   i,   l,   n,   p,   r,   s,   t,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9 */
    /*state 0*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 1*/  { 2,   2,   6,  15,  16,   0,  11,   0,   0,   0,   4,   0,   0,  23,   0,   0,   7,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },
    /*state 2*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },
    /*state 3*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3 },
    /*state 4*/  { 0,   0,   0,   0,   0,   0,   0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 5*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 6*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 7*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 8*/  { 0,   0,   0,   0,   0,   0,   9,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 9*/  { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  10,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 10*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 11*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  12,  21,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 12*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  13,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 13*/ { 0,   0,   0,   0,   0,   0,  14,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 14*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 15*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 16*/ { 0,   0,   0,   0,   0,   0,  17,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 17*/ { 0,   0,   0,   0,   0,   0,   0,   0,  18,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 18*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  19,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 19*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  20,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 20*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 21*/ { 0,   0,   0,   0,   0,  22,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 22*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 23*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  24,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 24*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  25,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 25*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  26,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 26*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  27,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 27*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 28*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28 },
};


int retorna_estado_seguinte(char caractere, int estado_atual) {
    int i;
    int estado_seguinte;

    for(i = 0; i < tamanho_do_alfabeto; i++) {
        if(caractere == alfabeto[i]) {
            estado_seguinte = edges[estado_atual][i];
            return estado_seguinte;
        }
    }

    return 0;
}

int verifica_se_estado_final(int estado_atual) {
    int i;
    for(i = 0; i < numero_de_estados_finais; i++) {
        if(estados_finais[i] == estado_atual)
            return true;
    }
    return false;
}

int retorna_estado_final(int estado_atual, int ultimo_estado_final) {
    if(verifica_se_estado_final(estado_atual))
        return estado_atual;

    return ultimo_estado_final;
}

int verifica_se_esta_no_alfabeto(char caractere) {
    int i;
    for(i = 0; i < tamanho_do_alfabeto; i++) {
        if(caractere == alfabeto[i])
            return true;
    }
    return false;   
}

void S();  //nao_terminal = 0
void L();  //nao_terminal = 1
void E();  //nao_terminal = 2

int getToken() {
    int estado_atual = 1;
    int contador = -1;
    int contador2 = 0;
    int ultimo_estado_final = retorna_estado_final(estado_atual, 0);
    int tokens_reconhecidos = 0;
    int i;

    char caractere_atual;
    char limite_reconhecido;
    char token_reconhecido[100];

    while(true) {
        limite_reconhecido = getchar();
        if(limite_reconhecido == '\n' || limite_reconhecido == ' ' ) {
            if(contador == -1 && limite_reconhecido == '\n')
                return EOL;
            fseek(stdin, -(contador+1), SEEK_CUR);
            token_reconhecido[strlen(token_reconhecido) - contador] = '\0';
            
            return tokens[ultimo_estado_final];
        }

        token_reconhecido[contador2] = limite_reconhecido;
        contador2++;


        contador++;
        // Verificacoes do que deve realmente identificar

        if(limite_reconhecido == EOF) {
            if(contador == 0)
                return ENDOF;

            token_reconhecido[strlen(token_reconhecido) - contador] = '\0';
            if(verifica_se_estado_final(estado_atual)) {
                return tokens[ultimo_estado_final];

            } else {
                fseek(stdin, -(contador), SEEK_CUR);
                return tokens[ultimo_estado_final];
            }
        }

        //  leitura da cadeia

        estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);

        //  verificacao se chegou ao final da cadeia

        ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);

        if(verifica_se_estado_final(estado_atual)) {
            caractere_atual = limite_reconhecido;
            contador = 0;
        }

        if(estado_atual == 0) {
            fseek(stdin, -(contador), SEEK_CUR);
        
            return tokens[ultimo_estado_final];
        }  
    }
}

int token;
int primeiro = true;
int erro = false;
int tipo_do_erro;

void success() {
    if(!primeiro) {        
        printf("\n");
    } else {
        primeiro = false;
    }
    printf("CADEIA ACEITA");
}

void error() {
    erro = true;

    if(!primeiro) {
        printf("\n");
    } else {
        primeiro = false;
    }
    
    printf("ERRO SINTATICO EM: %s ESPERADO: ", tokens_escritos[token]);
    switch (tipo_do_erro) {
        case 0:
            printf("if, begin, print");
            break;
        case 1:
            printf("end, ;");
            break;
        case 2:
            printf("num");
            break;
        case 3:
            printf("CADEIA INCOMPLETA");
            break;
    }       

}

void advance() {
    token = getToken();

}

void eat(int t) {
    if (token == t) {
        advance();
    } else {        
        error();
    }
}

void lida_com_erro() {
    char letra;
    while(true) {
        letra = getchar();
        if(letra == '\n' || letra == EOF)
            break;
    }
}
//IF=1, THEN=2, ELSE=3, BEGIN=4, END=5, PRINT=6, SEMI=7, NUM=8, EQ=9, ERR=0
void S(){
    erro=false;
    tipo_do_erro = 3;
    switch(token) {
        case IF: eat(IF); E(); eat(THEN); S(); eat(ELSE); S(); success(); break;
        case BEGIN: eat(BEGIN); S(); L(); success(); break;
        case PRINT: 
            eat(PRINT); 
            E(); 
            success(); 
            break;
        default: tipo_do_erro = 0; error(); 
    }
}
void L(){
    switch(token) {
        case END: eat(END); break;
        case SEMI: eat(SEMI); S(); L(); break;
        default: tipo_do_erro = 1; error(); 
    }
}
void E(){ 
    switch(token) {
        case NUM: 
            eat(NUM); 
            eat(EQ); 
            eat(NUM); 
            break;
        default: tipo_do_erro = 2; error(); 
    }
    return;
}


int main() {
    token = getToken();

    while(true) {
        S();
        token = getToken();
        if(token == ENDOF)
            break;
    }
    
    return 0;
}