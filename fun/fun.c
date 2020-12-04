#include <stdio.h>
#include <math.h>

int main() {
    float matriz[2][3] = {
        {6, 4, 12},
        {3, 2, 6},
    };

    float u[2][2];
    int n = 2;
    float l[2][2];
    int i, j, k;

    float values[2];
    float divisions[2];

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
                // printf("m[%d][%d]: %.2f %% m[%d][%d]: %.2f == %f || m[%d][%d] %% m[%d][%d] == %f\n", i, k, matriz[i][k], j, k, matriz[j][k], fmod(matriz[i][k], matriz[j][k]), j, k, i, k, fmod(matriz[j][k], matriz[i][k]));
                if(fmod(matriz[i][k], matriz[j][k]) != 0 && fmod(matriz[j][k], matriz[i][k]) != 0) {
                    break;
                }
                if(matriz[i][k] > matriz[j][k]) {
                    // printf("%f/%f", matriz[i][k],matriz[j][k]);
                    divisions[k] = matriz[i][k]/matriz[j][k];
                } else {
                    // printf("%f/%f", matriz[j][k],matriz[i][k]);
                    divisions[k] = matriz[j][k]/matriz[i][k];
                }
            }

            for(k= 0; k < n; k++) {

                if(divisions[k] != divisions[0]) {
                    break;
                }
                if(k == n-1 && (matriz[i][n]/divisions[0] == matriz[j][n] || matriz[j][n]/divisions[0] == matriz[i][n])) {
                    printf("Sistema Indeterminado.\n");
                    return 0;
                } else if(k == n-1 && (matriz[i][n]/divisions[0] != matriz[j][n] && matriz[j][n]/divisions[0] != matriz[i][n])) {
                    printf("Sistema Impossivel.\n");
                    return 0;
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
                matriz[i][2] -= l[i][j]*values[j];
            } else {
                values[i] = matriz[i][2]/l[i][j];
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
                matriz[i][2] -= u[i][j]*values[j];
            } else {
                values[i] = matriz[i][2]/u[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.1f ", u[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.1f ", l[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%.2f ", values[i]);
    }

    return 0;
}