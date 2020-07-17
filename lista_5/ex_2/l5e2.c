#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define tamanho_do_alfabeto 41
#define numero_de_tokens 14

char alfabeto[] = { '-', ' ', '.', '\n', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char tokens[][12] = { "", "", "ID", "IF", "ID", "error", "REAL", "NUM", "REAL", "error", "", "comment", "white space", "error" };

int edges[][tamanho_do_alfabeto] = {
    /*  symbols  -,  , ., \n,     a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,           0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */
    /*state 0*/ {0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 1*/ {9, 12, 5, 13,    4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,           7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    /*state 2*/ {0, 0, 0,  0,     4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,           4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    /*state 3*/ {0, 0, 0,  0,     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,           4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    /*state 4*/ {0, 0, 0,  0,     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,           4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    /*state 5*/ {0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    /*state 6*/ {0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    /*state 7*/ {0, 0, 8,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
    /*state 8*/ {0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    /*state 9*/ {10, 0, 0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 10*/{0, 0, 0, 11,     10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,          0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 11*/{0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 12*/{0, 12, 0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 13*/{0, 0, 0,  0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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
    if(estado_atual == 1)
        return 13;
    
    return 0;
}

int verifica_se_estado_final(int estado_atual) {
    int i;
    for(i = 0; i < tamanho_do_alfabeto; i++) {
        if(edges[estado_atual][i] == 0)
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

    char inicio_da_cadeia;
    char caractere_atual;
    char limite_reconhecido;

    while(true) {
        limite_reconhecido = getchar();

        // Verificacoes do que deve realmente identificar

        if(limite_reconhecido == EOF) {
            if(ultimo_estado_final != 12) {
                printf(" %s", tokens[ultimo_estado_final]);
            } else {
                printf("%s", tokens[ultimo_estado_final]);
            }
            break;
        }

        if(limite_reconhecido == '\n' && estado_atual != 10) {
            printf("\n");
            continue;
        }            

        //  Mudanças para inicios de novas cadeias 

        if(contador == 0) {
            inicio_da_cadeia = limite_reconhecido;     
        }

        //  leitura da cadeia

        estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);

        //  verificacao se chegou ao final da cadeia

        if(estado_atual == 0) {
            estado_atual = 1;
            contador = 0;
            if(ultimo_estado_final != 12) {
                printf(" %s\n", tokens[ultimo_estado_final]);
            } else {
                printf("%s\n", tokens[ultimo_estado_final]);
            }
            ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);
            estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);
        }

        ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);
        if(verifica_se_estado_final(estado_atual)) {
            caractere_atual = limite_reconhecido;
        }

        if(limite_reconhecido != '\n' && limite_reconhecido != ' ')
            printf("%c", limite_reconhecido);   

        contador++;   

    }

    return 0;
}