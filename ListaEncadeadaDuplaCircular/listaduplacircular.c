#include "listaduplacircular.h"

struct listad
{
    int dado;
    struct listad *prox;
    struct listad *ant;
};

// inicia a lista
Listad *listdc_cria(void)
{
    return NULL;
}

void listc_libera(Listad *l)
{
    Listad *p = l;
    if (p != NULL)
    {
        do
        {
            Listad *t = p->prox;
            free(p);
            p = t;
        } while (p != l);
        l = NULL; // Define l como NULL após liberar a lista
    }
}

// adiciona em uma lista dupla circular
Listad *listdc_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
    novo->dado = v;
    novo->prox = novo;
    novo->ant = novo;
    if (!l)
    {
        return novo;
    }
    else
    {
        Listad *ultimo = l->ant;
        novo->prox = l;
        l->ant = novo;
        ultimo->prox = novo;
        novo->ant = ultimo;
        return l;
    }
}

// busca um elemento
Listad *listdc_busca(Listad *l, int v)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado == v)
        {
            return p;
        }
    }
    return NULL; // não achou
}

Listad *listdc_retira(Listad *l, int v)
{
    Listad *p = listdc_busca(l, v);

    if (p == NULL)
    {
        return l; // não achou
    }

    // Retira o elemento
    if (l == p)
    {                     // Testa se é o primeiro elemento
        if (l->prox == l) // Se for o único elemento na lista
        {
            free(l);
            return NULL; // Retorna lista vazia
        }
        else
        {
            l = p->prox; // Atualiza o início da lista
        }
    }

    p->ant->prox = p->prox; // Retira o do meio ou do final
    p->prox->ant = p->ant;
    free(p);
    return l;
}

// verifica se a lista esta vazia
int listdc_vazia(Listad *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// imprime a lista
void listdc_imprime(Listad *l)
{
    if (l == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    Listad *p = l;
    do
    {
        printf("Dado = %d\n", p->dado);
        p = p->prox;
    } while (p != l);
}
