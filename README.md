# Lista Encadeada Simples (Linked List)

## Tópicos

- [Descrição](#descrição)
- [Estrutura](#estrutura)
- [Vantagens](#vantagens)
- [Desvantagens](#desvantagens)
- [TAD](#tad-lista)
- [Funções implementadas](#algumas-funções-da-lista-encadeada-simples)

### Descrição

- Uma lista encadeada simples em C é uma estrutura de dados que consiste em nós ligados em uma sequência, onde cada nó contém dois campos: um campo de dados para armazenar informações e um ponteiro que aponta para o próximo nó na lista.

- Chamos cada elemento da lista de nó, e um conjunto de nós é chamado de lista encadeada.

![Lista encadeada simples](https://github.com/JhoanDev/LinkedList/blob/main/ListaEncadeadaSimples/Img/Lista_encadeada_simples_representacao.png)

### Estrutura

```C
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

## TAD lista

### Porque utilizar uma TAD?

- **Reutilização de Código:** Uma vez que as operações da lista estão encapsuladas no TAD Lista, elas podem ser reutilizadas em diferentes partes do código ou em projetos diferentes sem a necessidade de reimplementação. Isso economiza tempo e esforço.

- **Encapsulamento:** O TAD Lista permite encapsular a implementação da lista. Isso significa que você pode mudar a implementação interna da lista sem afetar o código que a utiliza.

- **Ocultação de Complexidade:** A implementação de estruturas de dados como listas encadeadas pode ser complexa, envolvendo alocação de memória, gerenciamento de ponteiros e manipulação de nós. O TAD Lista oculta essa complexidade, tornando mais fácil para outros desenvolvedores usar a lista sem se preocupar com os detalhes complicados.

- **Padronização:** O TAD Lista estabelece um conjunto padrão de operações e nomes para trabalhar com listas. Isso torna o código mais consistente e fácil de entender para qualquer desenvolvedor.

- **Facilita a Depuração:** Se ocorrer um erro em uma operação da lista, é mais fácil depurar(Achar o erro) quando você tem uma interface clara e bem definida para a lista. Você pode isolar o problema mais facilmente.

- **Documentação:** O TAD Lista serve como documentação clara das operações suportadas pela lista. Isso ajuda a vocês (desenvolvedores) a entender como usar a lista corretamente.

### **Algumas funções da TAD Lista:**

### lst_cria

- **Descrição:** Cria uma lista encadeada vazia.

```c
Lista *lst_cria(void)
{
    return NULL;
}
```

- **Uso:**

```c
Lista *lista = lst_cria();
```

### lst_insere

- **Descrição:** Insere um novo elemento no início da lista.

```c
Lista *lst_insere(Lista *l, int v)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("[ERRO] Memória insuficiente!");
        exit(1);
    }
    novo->info = v;
    novo->prox = l;
    return novo;
}
```

- **Uso:**

```c
lista = lst_insere(lista, 42);
```

### lst_vazia

- **Descrição:** Verifica se a lista está vazia.

```c
int lst_vazia(Lista *l)
{
    return (l == NULL);
}
```

- **Uso:**

```c
if (lst_vazia(lista)) {
    printf("A lista está vazia.\n");
}
```

### lst_imprime

- **Descrição:** Imprime os elementos da lista.

```c
void lst_imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf(" Info = %d \n", p->info);
    }
}
```

- **Uso:**

```c
lst_imprime(lista);
```

### lst_busca

- **Descrição:** Busca por um elemento na lista.

```c
Lista *lst_busca(int elemento, Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == elemento)
            return p;
    }
    return NULL;
}
```

- **Uso:**

```c
Lista *resultado = lst_busca(42, lista);
```

### lst_retira

- **Descrição:** Remove um elemento da lista.

```c
Lista *lst_retira(Lista *l, int v)
{
    Lista *ant = NULL;
    Lista *p = l;
    while (p->info != v)
    {
        if (p == NULL)
            return l;
        ant = p;
        p = p->prox;
    }
    if (ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}
```

- **Uso:**

```c
lista = lst_retira(lista, 42);
```

### lst_libera

- **Descrição:** Libera a memória ocupada pela lista.

```c
void lst_libera(Lista *l)
{
    Lista *p = l;
    Lista *t;
    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
}
```

- **Uso:**

```c
lst_libera(lista);
```

### lst_insere_ordenada

- **Descrição:** Insere um elemento de forma ordenada na lista.

```c
Lista *lst_insere_ordenada(Lista *l, int v)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;
    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }
    novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;
    if (ant == NULL)
    {
        novo->prox = l;
        l = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}
```

- **Uso:**

```c
lista = lst_insere_ordenada(lista, 42);
```

### lst_ler_arquivo

- **Descrição:** Lê valores de um arquivo e insere na lista.

```c
Lista *lst_ler_arquivo(char *nome_arquivo)
{
    FILE *arquivo;
    int valor;
    Lista *l = lst_cria();
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    while (fscanf(arquivo, "%d", &valor) != EOF)
    {
        l = lst_insere(l, valor);
    }
    fclose(arquivo);
    return l;
}
```

- **Uso:**

```c
lista = lst_ler_arquivo("dados.txt");
```
