#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct 
{
    int idade;
    float peso;
    char nome[MAX];
} pessoa;

// Função de busca binária para encontrar uma pessoa pelo peso
int busca_binaria(pessoa vetor[], float peso_procurado, int tamanho);

int main()
{
    int tamanho;
    
    // Entrada do tamanho do vetor de pessoas
    printf("Digite quantas pessoas terao no seu vetor (maximo 50): ");
    scanf("%d", &tamanho);
    getchar(); // Consumir o '\n' pendente no buffer de entrada
    
    // Verificação do limite do vetor
    if (tamanho < 1 || tamanho > MAX) {
        printf("Tamanho invalido. O vetor deve ter entre 1 e %d pessoas.\n", MAX);
        return 1;
    }

    pessoa vetor[tamanho];

    // Leitura dos dados das pessoas
    for(int i = 0; i < tamanho; i++)
    {
        printf("Digite a idade da pessoa %d no vetor: ", i + 1);
        scanf("%d", &vetor[i].idade);
        getchar(); // Consumir o '\n' pendente no buffer de entrada

        printf("Digite o peso da pessoa %d no vetor: ", i + 1);
        scanf("%f", &vetor[i].peso);
        getchar(); // Consumir o '\n' pendente no buffer de entrada

        printf("Digite o nome da pessoa %d no vetor: ", i + 1);
        fgets(vetor[i].nome, MAX, stdin);
        // Remover o caractere de nova linha do nome, se presente
        size_t len = strlen(vetor[i].nome);
        if (len > 0 && vetor[i].nome[len - 1] == '\n') {
            vetor[i].nome[len - 1] = '\0';
        }
    }

    // Ordenação do vetor por peso em ordem crescente
    for(int i = 0; i < tamanho - 1; i++)
    {
        for(int j = 0; j < tamanho - i - 1; j++)
        {
            if(vetor[j].peso > vetor[j + 1].peso) // Ordem crescente
            {
                pessoa aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux; 
            }
        }
    }
    float peso_procurar;
    printf("Digite o peso da pessoa que deve ser procurada: ");
    scanf("%f", &peso_procurar);
    
    int peso_achado = busca_binaria(vetor, peso_procurar, tamanho);

    // Verificação se o peso foi encontrado
    if(peso_achado == -1)
    {
        printf("Nao exite ninguem com esse peso dentro do vetor.\n");
        return 1;
    }
    printf("A pessoa com esse peso eh: %s\n", vetor[peso_achado].nome);

    return 0;
}

// Implementação da busca binária
int busca_binaria(pessoa vetor[], float peso_procurado, int tamanho)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while(esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;

        if(vetor[meio].peso == peso_procurado)
        {
            return meio;
        }
        if(vetor[meio].peso > peso_procurado) // Busca binária em ordem crescente
        {
            direita = meio - 1;
        }
        else
        {
            esquerda = meio + 1;
        }
    }
    return -1;
}
