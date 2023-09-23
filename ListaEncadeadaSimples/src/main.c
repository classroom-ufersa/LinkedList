#include "lista.c"

int main() {
    Lista *lista = lst_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    lista = lst_insere(lista, 42);
    lista = lst_insere(lista, 17);
    lista = lst_insere(lista, 65);
    lista = lst_insere(lista, 23);

    printf("Lista apos insercao de elementos:\n");
    lst_imprime(lista);
	printf("\n");

    // Verifica se a lista está vazia
    if (lst_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }
	printf("\n");

    // Busca um elemento na lista
    Lista *resultadoBusca = lst_busca(65, lista);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultadoBusca->info);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
	printf("\n");

    // Remove um elemento da lista
    lista = lst_retira(lista, 17);
    printf("Lista apos a remocao do elemento %d:\n", 17);
    lst_imprime(lista);
	printf("\n");

    // Insere um elemento de forma ordenada na lista
    int elementoOrdenado = 10;
    lista = lst_insere_ordenada(lista, elementoOrdenado);
    printf("Lista apos a insercao ordenada do elemento %d:\n", elementoOrdenado);
    lst_imprime(lista);
	printf("\n");

    // Libera a memória da lista
    lst_libera(lista);

    // Lê valores de um arquivo e insere na lista
    lista = lst_ler_arquivo("entrada.txt");
    printf("Lista apos a leitura do arquivo:\n");
    lst_imprime(lista);

    // Libera a memória da lista novamente
    lst_libera(lista);

    return 0;
}
