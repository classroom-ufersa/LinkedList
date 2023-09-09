# Lista Encadeada Simples (Linked List)

## Tópicos

- [Descrição](#descrição)
- [Estrutura](#estrutura)
- [Vantagens](#vantagens)
- [Desvantagens](#desvantagens)

### Descrição

- Uma lista encadeada simples em C é uma estrutura de dados que consiste em nós ligados em uma sequência, onde cada nó contém dois campos: um campo de dados para armazenar informações e um ponteiro que aponta para o próximo nó na lista.

- Chamos cada elemento da lista de nó, e um conjunto de nós é chamado de lista encadeada.

![Lista encadeada simples](https://github.com/JhoanDev/LinkedList/blob/main/ListaEncadeadaSimples/Img/Lista_encadeada_simples_representacao.png)

### Estrutura

```
struct lista
{
    int info;
    struct lista *prox;
};
```

- **Info:** Representa o dado armazenado na lista, que, no exemplo acima, é um valor inteiro. No entanto, pode ser utilizado para armazenar qualquer tipo de dado, inclusive estruturas (como a struct aluno, por exemplo).

- **Prox:** Armazena o endereço do próximo elemento da lista. Em outras palavras, cada nó mantém um ponteiro para o próximo elemento usando este campo.

### Vantagens

1. **Alocação Dinâmica de Memória:** Permite a alocação dinâmica de memória, facilitando a adição e remoção de elementos conforme necessário.

2. **Inserção e Exclusão Eficientes:** Inserir ou excluir elementos no início é eficiente, minimizando a necessidade de deslocamento de dados.

3. **Redimensionamento Dinâmico:** A lista pode crescer ou encolher conforme necessário, adequando-se a tamanhos variáveis de dados.

### Desvantagens

1. **Acesso direto ineficiente:** O acesso a um elemento específico requer percorrer a lista, o que é menos eficiente que arrays para acesso direto por índice.

2. **Gasto de memória extra por elemento:** Cada nó requer espaço extra para o ponteiro, aumentando o consumo de memória em comparação com arrays.

3. **Complexidade de implementação:** Implementar operações pode ser mais complexo devido à gestão de ponteiros e alocação dinâmica de memória.
