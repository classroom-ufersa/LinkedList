#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

// imprimir a informação
void listc_imprime(Lista *l);

// inserindo no inicio
Lista *listc_adc(Lista *l, int i);

// função para buscar um elemento da lista circular
Lista *listc_busca(Lista *l, int v);

// função para retirar um elemento
Lista *listc_retira(Lista *l, int v);

// verifica se a lista esta vazia
int listc_vazia(Lista *l);

// inicia a lista
Lista *listc_cria(void);

// libera os nos da lista
void listc_libera(Lista *l);