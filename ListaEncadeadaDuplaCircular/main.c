#include "listaduplacircular.c"

int main()
{
    Listad *lista = listdc_cria(); // Inicializa a lista

    printf("Verificando se a lista está vazia: %s\n", listdc_vazia(lista) ? "Sim" : "Não");

    lista = listdc_adc(lista, 10); // Adiciona elementos
    lista = listdc_adc(lista, 20);
    lista = listdc_adc(lista, 30);
    lista = listdc_adc(lista, 40);

    printf("Lista após adicionar elementos:\n");
    listdc_imprime(lista);

    int elementoBuscado = 20;
    Listad *resultadoBusca = listdc_busca(lista, elementoBuscado);
    if (resultadoBusca != NULL)
    {
        printf("Elemento %d encontrado na lista.\n", elementoBuscado);
    }
    else
    {
        printf("Elemento %d não encontrado na lista.\n", elementoBuscado);
    }

    int elementoRetirar = 30;
    lista = listdc_retira(lista, elementoRetirar);
    printf("Lista após retirar o elemento %d:\n", elementoRetirar);
    listdc_imprime(lista);

    listc_libera(lista); // Libera a memória alocada pela lista
    
    return 0;
}
