#include "listacircular.c"

int main()
{
    Lista *lista = listc_cria(); // Cria uma lista circular vazia

    // Insere elementos na lista
    lista = listc_adc(lista, 10);
    lista = listc_adc(lista, 20);
    lista = listc_adc(lista, 30);

    // Imprime a lista
    printf("Lista circular:\n");
    listc_imprime(lista);

    // Verifica se a lista está vazia
    if (listc_vazia(lista))
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("A lista não está vazia.\n");
    }

    // Busca um elemento na lista
    int elementoBuscado = 20;
    Lista *elementoEncontrado = listc_busca(lista, elementoBuscado);
    if (elementoEncontrado != NULL)
    {
        printf("Elemento %d encontrado na lista.\n", elementoBuscado);
    }
    else
    {
        printf("Elemento %d não encontrado na lista.\n", elementoBuscado);
    }

    // Remove um elemento da lista
    int elementoRemover = 20;
    lista = listc_retira(lista, elementoRemover);

    // Imprime a lista após a remoção
    printf("Lista circular após a remoção do elemento %d:\n", elementoRemover);
    listc_imprime(lista);

    // Libera a lista
    listc_libera(lista);
    
    return 0;
}
