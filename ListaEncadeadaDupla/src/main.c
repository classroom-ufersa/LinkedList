#include "listadupla.c"

int main() {
    Listad *lista = listd_cria();

    // Adiciona valores à lista
    lista = listd_adc(lista, 10);
    lista = listd_adc(lista, 20);
    lista = listd_adc(lista, 30);
    lista = listd_adc(lista, 40);

    // Imprime a lista
    printf("Lista:\n");
    listd_imprime(lista);

    // Busca um valor na lista
    int valor_busca = 20;
    Listad *resultado = listd_busca(lista, valor_busca);
    if (resultado != NULL) {
        printf("Valor %d encontrado na lista.\n", valor_busca);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor_busca);
    }

    // Remove um valor da lista
    int valor_remover = 30;
    lista = listd_retira(lista, valor_remover);
    printf("Lista após a remoção do valor %d:\n", valor_remover);
    listd_imprime(lista);

    // Verifica se a lista está vazia
    if (listd_vazia(lista)) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista não está vazia.\n");
    }

    // Libera a memória alocada
    listd_libera(lista);

    return 0;
}
