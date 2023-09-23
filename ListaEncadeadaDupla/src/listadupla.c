#include "listadupla.h"

struct listad
{
    int dado;
    struct listad *prox;
    struct listad *ant;
};

// inicia a lista
Listad *listd_cria(void)
{
    return NULL;
}

// libera os nos da lista
void listd_libera(Listad *l)
{
    Listad *p = l;
    while (p != NULL)
    {
        Listad *t = p->prox;
        free(p);
        p = t;
    }
}

// adiciona um novo valor na lista
Listad *listd_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] Memória insuficiente!");
        exit(1);
    }
    novo->dado = v;
    novo->prox = NULL;
    novo->ant = NULL;

    if (l == NULL)
    {
        return novo;
    }

    Listad *ultimo = l;
    while (ultimo->prox != NULL)
    {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->ant = ultimo;

    return l;
}

// busca um item na lista
Listad *listd_busca(Listad *l, int v)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado == v)
        {
            return p;
        }
    }
    return NULL; // nao achou
}

// retira um no da lista
Listad *listd_retira(Listad *l, int v)
{
    Listad *p = listd_busca(l, v);

    if (p == NULL)
    {
        return l; // não achou
    }
    // retira o elemento
    if (l == p) // testa se é o primeiro elemento
    {
        l = p->prox;
    }
    else
    {
        p->ant->prox = p->prox; // retira o do meio
    }
    if (p->prox != NULL) // testa se é o ultimo elemento
    {
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

// verifica se a lista esta vazia
int listd_vazia(Listad *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// imprime o valor de todos os valores da lista
void listd_imprime(Listad *l)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("Dado = %d\n", p->dado);
    }
}