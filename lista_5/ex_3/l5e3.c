#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define tamanho_do_alfabeto 2
#define numero_de_tokens 10
#define numero_de_estados_finais 4

char alfabeto[] = { 'a', 'b' };
char tokens[][11] = { "", "", "(action 3)", "(action 3)", "", "(action 1)", "", "", "(action 2)", "" };
int estados_finais[] = { 2, 3, 5, 8 };

int edges[][tamanho_do_alfabeto] = {
    /*  symbols  a, b
    /*state 0*/ {0, 0},
    /*state 1*/ {2, 3},
    /*state 2*/ {8, 4},
    /*state 3*/ {0, 0},
    /*state 4*/ {5, 9},
    /*state 5*/ {6, 0},
    /*state 6*/ {0, 7},
    /*state 7*/ {5, 0},
    /*state 8*/ {0, 0},
    /*state 9*/ {8, 9}
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

    char inicio_da_cadeia;
    char caractere_atual;
    char limite_reconhecido;
    int x = 0;

    while(true) {
        limite_reconhecido = getchar();
        contador++;
        // Verificacoes do que deve realmente identificar

        if(limite_reconhecido == EOF) {
            if(verifica_se_estado_final(estado_atual)) {
                printf("%s\n", tokens[ultimo_estado_final]);
            } else {
                fseek(stdin, -(contador), SEEK_CUR);
                estado_atual = 1;
                printf("%s\n", tokens[ultimo_estado_final]);
                limite_reconhecido = getchar();
                estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);    
                printf("Esta no estado 1, leu %c", limite_reconhecido);
                printf(", foi para o estado %d\n", estado_atual);
                printf("%s", tokens[estado_atual]);
            }
            break;
        }

        //  Mudanças para inicios de novas cadeias 

        if(contador == 0) {
            inicio_da_cadeia = limite_reconhecido;     
        }

        printf("Esta no estado %d, leu %c", estado_atual, limite_reconhecido);

        //  leitura da cadeia

        estado_atual = retorna_estado_seguinte(limite_reconhecido, estado_atual);

        printf(", foi para o estado %d", estado_atual);

        //  verificacao se chegou ao final da cadeia

        ultimo_estado_final = retorna_estado_final(estado_atual, ultimo_estado_final);
        printf(" ulitmo estado final %d\n", ultimo_estado_final);
        if(verifica_se_estado_final(estado_atual)) {
            caractere_atual = limite_reconhecido;
            contador = 0;
        }

        // if(limite_reconhecido != '\n' && limite_reconhecido != ' ')
        //     printf("%c", limite_reconhecido);   

        if(estado_atual == 0) {
            fseek(stdin, -(contador), SEEK_CUR);
            estado_atual = 1;
            contador = -1;
            
            printf("%s\n", tokens[ultimo_estado_final]);
            ultimo_estado_final = 0;
        }  
        x++;
    }

    return 0;
}