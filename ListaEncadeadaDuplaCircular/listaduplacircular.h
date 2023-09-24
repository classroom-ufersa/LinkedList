#include <stdio.h>
#include <stdlib.h>

/* TAD: lista de inteiros */
typedef struct listad Listad;

// cria a lista dupla circular
Listad *listdc_cria(void);

// libera os nós da lista
void listc_libera(Listad *l);

// adiciona em uma lista dupla circular
Listad *listdc_adc(Listad *l, int v);

// busca um elemento
Listad *listdc_busca(Listad *l, int v);

// retira um elemento
Listad *listdc_retira(Listad *l, int v);

// verifica se a lista esta vazia
int listdc_vazia(Listad *l);

// imprime a lista
void listdc_imprime(Listad *l);