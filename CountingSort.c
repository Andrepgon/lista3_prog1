#include <stdio.h>

void countingSort(int vetor[], int tamanho, int maximo);

int main()
{
    int tamanho;
    printf("Qual tamanho do seu vetor: ");
    scanf("%d", &tamanho);

    int vetor_desordenado[tamanho];

    printf("Digite os valores do vetor: ");

    for(int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor_desordenado[i]);
    }

    int maximo = vetor_desordenado[0];

    for(int i = 1; i < tamanho; i++)
    {
        if(vetor_desordenado[i] > maximo)
        {
            maximo = vetor_desordenado[i];
        }
    }

    countingSort(vetor_desordenado, tamanho, maximo);

    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor_desordenado[i]);
    }
    return 0;
}




void countingSort(int vetor[], int tamanho, int maximo)
{
    //inicializando dois vetores com todos elementos sendo iguais a zero
    int vetor_contagem[maximo+1];
    for(int i = 0; i < maximo+1; i++)
    {
        vetor_contagem[i] = 0;
    }
    int vetor_ordenado[tamanho];
    for(int i = 0; i < tamanho; i++)
    {
        vetor_ordenado[i] = 0;
    }
    //criando o vetor_contagem baseado no vetor dado para a função
    for(int i = 0; i < tamanho; i++)
    {
        vetor_contagem[vetor[i]]++;
    }
    //passando os valores do vetor contagem para o vetor ordenado
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < maximo+1; j++)
        {
            if(vetor_contagem[j] != 0) 
            {
                vetor_contagem[j]--;
                vetor_ordenado[i] = j;
                break;
            }
        }
    }
    //passando o vetor ordenado para o vetor recebido(desordenado)
    for(int i = 0; i< tamanho; i++)
    {
        vetor[i] = vetor_ordenado[i];
    }
    return;
}
