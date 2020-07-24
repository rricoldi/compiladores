#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define tamanho_do_alfabeto 38
#define numero_de_tokens 23
#define numero_de_estados_finais 12

char alfabeto[] = { '+', '-', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char tokens[][10] = { "ERRO", "ERRO", "ERRO", "ELE", "ERRO", "ERRO", "ELA", "ERRO", "DELE", "ERRO", "DELA", "ERRO", "ERRO", "GATO", "CARRO", "GATOS", "CARROS", "MAIS", "MENOS", "INTEIRO", "ERRO", "ERRO", "REAL" };
int estados_finais[] = { 3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22 };

int edges[][tamanho_do_alfabeto] = {
    /*  symbols    +,  -,   a,   b,   c,   d,   e,   f,   g,   h,   i,   j,   k,   l,   m,   n,   o,   p,   q,   r,   s,   t,   u,   v,   w,   x,   y,   z,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9 */
    /*state 0*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 1*/ { 17, 18,   0,   0,  11,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   4,   0,   0,   0,   0,   0,   0,   0,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19 }, 
    /*state 2*/ { 0,   0,   0,   0,   0,   0,   3,   0,   0,   0,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 3*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   9,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 4*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 5*/ { 0,   0,   0,   0,   0,   0,   6,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 6*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 7*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 8*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 9*/ { 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  10,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 10*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 11*/ { 0,  0,  12,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 12*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  14,   0,  13,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 13*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 14*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  16,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 15*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 16*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 17*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 18*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
    /*state 19*/ { 0,  0,   0,   0,   0,   0,  20,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  19,  19,  19,  19,  19,  19,  19,  19,  19,  19 },
    /*state 20*/ {21, 21,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22 },
    /*state 21*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22 },
    /*state 22*/ { 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22 },
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

int main() {
    int estado_atual = 1;
    int contador = 0;
    int ultimo_estado_final = retorna_estado_final(estado_atual, 0);

    char caractere_atual;
    char limite_reconhecido;

    while(true) {
        limite_reconhecido = getchar();
        if(limite_reconhecido == '\n' || limite_reconhecido == ' ' ) {
            if(contador == -1)
                continue;
            estado_atual = 1;
            contador = -1;
            
            printf("%s\n", tokens[ultimo_estado_final]);
            ultimo_estado_final = 0;
            continue;
        }

        contador++;
        // Verificacoes do que deve realmente identificar

        if(limite_reconhecido == EOF) {
            if(contador == 0)
                break;
            if(verifica_se_estado_final(estado_atual)) {
                printf("%s\n", tokens[ultimo_estado_final]);
            } else {
                fseek(stdin, -(contador), SEEK_CUR);
                estado_atual = 1;
                printf("%s\n", tokens[ultimo_estado_final]);
                limite_reconhecido = getchar();
                estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);    
            }
            break;
        }

        // printf("Esta no estado %d, leu %c", estado_atual, limite_reconhecido);

        //  leitura da cadeia

        estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);

        // printf(", foi para o estado %d", estado_atual);

        //  verificacao se chegou ao final da cadeia

        ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);
        // printf(" ulitmo estado final %d\n", ultimo_estado_final);
        if(verifica_se_estado_final(estado_atual)) {
            caractere_atual = limite_reconhecido;
            contador = 0;
        }

        if(estado_atual == 0) {
            fseek(stdin, -(contador), SEEK_CUR);
            estado_atual = 1;
            contador = -1;
            
            printf("%s\n", tokens[ultimo_estado_final]);
            ultimo_estado_final = 0;
        }  
    }

    return 0;
}