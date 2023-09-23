/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"

struct lista
{
	int info;
	struct lista *prox;
};

Lista *lst_cria(void)
{
	return NULL;
}

Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	if (novo == NULL)
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;
	novo->prox = l;
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l)
{
	return (l == NULL);
}

void lst_imprime(Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		printf("\tInfo = %d \n", p->info);
	}
}

Lista *lst_busca(int elemento, Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == elemento)
			return p;
	}

	return NULL;
}

Lista *lst_retira(Lista *l, int v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* n�o achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

void lst_libera(Lista *l)
{
	Lista *p = l;
	Lista *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenada(Lista *l, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }
    novo->info = valor;
    novo->prox = NULL;

    if (l == NULL || valor < l->info) {
        novo->prox = l;
        return novo;
    }

    Lista *ant = NULL;
    Lista *atual = l;

    while (atual != NULL && valor > atual->info) {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;

    return l;
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}
