#include "listacircular.h"

struct lista
{
    int dado;
    struct lista *prox;
};

// imprimir a informação
void listc_imprime(Lista *l)
{
    Lista *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p = p->prox;
    } while (p != l);
}

// inserindo no inicio
Lista *listc_adc(Lista *l, int i)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->dado = i;
    if (l == NULL) // se a lista estiver vazia
    {
        novo->prox = novo; // o próximo aponta para si mesmo
        return novo;       // retorna a nova célula como primeira e última
    }
    novo->prox = l->prox; // o próximo aponta para a primeira célula
    l->prox = novo;       // atualiza o próximo da última célula para apontar para a nova célula
    return l;             // retorna a primeira célula da lista
}

// função para buscar um elemento da lista c
Lista *listc_busca(Lista *l, int v)
{
    Lista *p = l;
    while (p != NULL && p->prox != l && p->dado != v)
    {
        p = p->prox;
        if (p->dado == v)
            return p;
    }
    return NULL;
}

// função para retirar um elemento
Lista *listc_retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;
    while (p != NULL && p->dado != v)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    ant->prox = p->prox;
    free(p);
    return l;
}

// verifica se a lista esta vazia
int listc_vazia(Lista *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// inicia a lista
Lista *listc_cria(void)
{
    return NULL;
}

// libera os nós da lista
void listc_libera(Lista *l)
{
    Lista *p = l;
    if (p != NULL)
    {
        do
        {
            Lista *t = p->prox;
            free(p);
            p = t;
        } while (p != l);
    }
}
