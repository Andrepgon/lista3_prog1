#include <stdio.h>

typedef struct 
{
    int elemento[3][3];
}matriz; // estrutura matriz que possui um array bidimensional, simulando a matriz

int calcular_determinante(matriz matriz);

int main()
{
    matriz matriz;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("Digite o elemento(%d,%d) da matriz:  ", i,j); //nested loop para conseguir fazer o scanf de todos os elementos da matriz 
            scanf("%d", &matriz.elemento[i][j]);
        }
    }

    printf("O determinante da matriz eh: %d", calcular_determinante(matriz));
    return 0;
}

int calcular_determinante(matriz matriz) //calcula o determinante da matriz
{
    int d1, d2, determinante;

    d1 = (matriz.elemento[0][0]*matriz.elemento[1][1]*matriz.elemento[2][2]) + 
        (matriz.elemento[0][1]*matriz.elemento[1][2]*matriz.elemento[2][0]) + 
        (matriz.elemento[0][2]*matriz.elemento[1][0]*matriz.elemento[2][1]);

    d2 = (matriz.elemento[0][0]*matriz.elemento[1][2]*matriz.elemento[2][1]) + 
        (matriz.elemento[0][1]*matriz.elemento[1][0]*matriz.elemento[2][2]) + 
        (matriz.elemento[0][2]*matriz.elemento[1][1]*matriz.elemento[2][0]);

    determinante = d1 - d2;

    return determinante;
}
