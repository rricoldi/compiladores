#include <stdio.h>

#define true 1
#define false 0
#define tamanho_do_alfabeto 38

char alfabeto[] = { '+', '-', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int edges[][tamanho_do_alfabeto] = {
    /*  symbols  +, -,     a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,           0, 1, 2, 3, 4, 5, 6, 7, 8, 9 */
    /*state 0*/ {0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 1*/ {3, 4,     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,           5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    /*state 2*/ {0, 0,     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,           2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    /*state 3*/ {0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 4*/ {0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 5*/ {0, 0,     0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
    /*state 6*/ {7, 7,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    /*state 7*/ {0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    /*state 8*/ {0, 0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,           8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
};

int retorna_estado_seguinte(char caractere, int estado_atual) {
    int i;
    int estado_seguinte;

    for(i = 0; i < tamanho_do_alfabeto; i++) {
        if(caractere == alfabeto[i]) {
            estado_seguinte = edges[estado_atual][i];
            break;
        }
    }

    return estado_seguinte;
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
    int ultimo_estado_final = 0;
    int estado_atual = 1;
    int contador = 0;

    ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);

    char inicio_da_cadeia;
    char caractere_atual;
    char limite_reconhecido;

    while(true) {
        limite_reconhecido = getchar();
        
        // Verificacoes do que deve realmente identificar

        if(limite_reconhecido == EOF)
            break;
        
        if(limite_reconhecido == '\n') {
            printf("\n");
            continue;
        }            
        
        if(!verifica_se_esta_no_alfabeto(limite_reconhecido)) {
            printf("\nERRO");
            estado_atual = 1;
            contador = -1;
            ultimo_estado_final = 0;
            continue;
        }

        //  Mudanças para inicios de novas cadeias

        if(contador == -1) {
            printf("\n");
            contador++;
        }

        if(contador == 0) {
            inicio_da_cadeia = limite_reconhecido;     
        }

        //  leitura da cadeia

        estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);

        //  verificacao se chegou ao final da cadeia

        if(estado_atual == 0) {
            estado_atual = 1;
            contador = 0;
            ultimo_estado_final = 0;
            estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);
            printf("\n");
        }

        ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);
        if(verifica_se_estado_final(estado_atual)) {
            caractere_atual = limite_reconhecido;
        }

        printf("%c", limite_reconhecido);     

        contador++;   
    }

    return 0;
}