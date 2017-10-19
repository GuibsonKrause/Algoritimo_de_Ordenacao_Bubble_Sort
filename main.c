#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fabricantes
{
	char nome[50];
	char nacionalidade[50];
	int ano;
}Fabricantes;

//======================================ASSINATURAS DAS FUNCOES===================================================
void swapbubble (Fabricantes *vetor, int i);
int Comparacao (Fabricantes *vet, int i);
void bubbleSort (Fabricantes *vetor, int qtd);
void escrVetor(Fabricantes *Fabricantes, int n);
//======================================FUNCAO PRINCIPAL=========================================================
int main()
 {
	Fabricantes  vetor[6];

	strcpy(vetor[0].nome, "Fiat");
	strcpy(vetor[0].nacionalidade, "Brasil");
	vetor[0].ano = 2000;

	strcpy(vetor[1].nome, "Fiat");
	strcpy(vetor[1].nacionalidade, "Brasil");
	vetor[1].ano = 1999;

	strcpy(vetor[2].nome, "Fox");
	strcpy(vetor[2].nacionalidade, "Colombia");
	vetor[2].ano = 1998;

	strcpy(vetor[3].nome, "Toyota");
	strcpy(vetor[3].nacionalidade, "Japao");
	vetor[3].ano = 1997;

	strcpy(vetor[4].nome, "Wolskwagen");
	strcpy(vetor[4].nacionalidade, "Coreia");
	vetor[4].ano = 1996;

	strcpy(vetor[5].nome, "Mazda");
	strcpy(vetor[5].nacionalidade, "Paraguai");
	vetor[5].ano = 1995;
	
	bubbleSort (vetor, 6);
	escrVetor (vetor, 6);
	return 0;
}
//======================================FUNCOES===================================================
void swapbubble (Fabricantes *vetor, int i)
{
	Fabricantes aux;
	aux = vetor[i];
	vetor[i] = vetor[i + 1];
	vetor[i + 1] = aux;
}

int Comparacao (Fabricantes *vet, int i)
{
	if(strcmp(vet[i].nome, vet[i + 1].nome) == -1)
	{
		return 0;
	}
	if (strcmp(vet[i].nome, vet[i+1].nome) == 0)
	{
		if(strcmp(vet[i].nacionalidade, vet[i + 1].nacionalidade) == -1)
		{
			return 0;
		}
		if (strcmp(vet[i].nacionalidade, vet[i + 1].nacionalidade) == 0)
		{
			if (vet[i].ano <= vet[i + 1].ano)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}
				
void bubbleSort (Fabricantes *vetor, int qtd)
{
	int i, trocou;
	do
	{
		qtd--;
		trocou = 0;
		for(i = 0; i < qtd; i++)
		{
			if(Comparacao(vetor, i))
			{
				swapbubble(vetor, i);
				trocou = 1;
			}
		}
	}
	while (trocou);
}

void escrVetor(Fabricantes *Fabricantes, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\n %s\n %s\n %d \n\n", Fabricantes[i].nome, Fabricantes[i].nacionalidade, Fabricantes[i].ano);
	}
}
