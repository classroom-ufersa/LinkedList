#include <stdio.h>
#include <stdlib.h>

/* TAD: lista de inteiros */
typedef struct listad Listad;

// inicia a lista
Listad *listd_cria(void);

// libera os nos da lista
void listd_libera(Listad *l);

// adiciona um novo valor na lista
Listad *listd_adc(Listad *l, int v);

// busca um item na lista
Listad *listd_busca(Listad *l, int v);

// retira um no da lista
Listad *listd_retira(Listad *l, int v);

// verifica se a lista esta vazia
int listd_vazia(Listad *l);

// imprime o valor de todos os valores da lista
void listd_imprime(Listad *l);
