#include <stdio.h>
#include <string.h>

int procuraPalavra(char* texto, char* palavra)
{
    int tamanhoT = strlen(texto);
    int tamanhoP = strlen(palavra);

    for(int i = 0 ; i < tamanhoT; i++)
    {
        int j;
        for(j = 0; j < tamanhoP; j++)
        {
            if(texto[i+j] != palavra[j])
            {
                break;
            }
        }
        if (j == tamanhoP - 1)
        {
            return i;
        }
    }
    return -1
}

int main(int argc, char* argv[])
{
    char texto[100];
    char palavra[100];

    puts("Digite a palavra para ser procurada");   
}

