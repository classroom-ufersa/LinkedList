# Listas Encadeadas (Linked List)

## Tópicos

- [Introdução](#introdução)
- [Porque Utilizar TADS?](#porque-utilizar-uma-tad)
- [Listas Encadeadas Simples](#listas-encadeadas-simples)
  - [Descrição](#descrição-lista-simples)
  - [Estrutura](#estrutura-lista-simples)
  - [Vantagens](#vantagens-lista-simples)
  - [Desvantagens](#desvantagens-lista-simples)
  - [Algumas Funções da TAD Lista](#algumas-funções-da-tad-lista)
- [Listas Encadeadas Duplas](#listas-encadeadas-duplas)
  - [Descrição](#descrição-lista-dupla)
  - [Estrutura](#estrutura-lista-dupla)
  - [Vantagens](#vantagens-lista-dupla)
  - [Desvantagens](#desvantagens-lista-dupla)
  - [Algumas Funções da TAD Lista Dupla](#algumas-funções-da-tad-lista-dupla)
- [Listas Encadeadas Circulares Simples](#listas-encadeadas-circulares-simples)
  - [Descrição](#descrição-lista-circular-simples)
  - [Estrutura](#estrutura-lista-circular-simples)
  - [Vantagens](#vantagens-lista-circular-simples)
  - [Desvantagens](#desvantagens-lista-circular-simples)
  - [Algumas Funções da TAD Lista Circular Simples](#algumas-funções-da-tad-lista-circular-simples)



## Introdução

Uma lista encadeada é uma estrutura de dados que consiste em nós ligados em uma sequência, onde cada nó contém campos: um campo de dados para armazenar informações e para ponteiros.

## Porque utilizar uma TAD?

- **Reutilização de Código:** Uma vez que as operações da lista estão encapsuladas no TAD Lista, elas podem ser reutilizadas em diferentes partes do código ou em projetos diferentes sem a necessidade de reimplementação. Isso economiza tempo e esforço.

- **Encapsulamento:** O TAD Lista permite encapsular a implementação da lista. Isso significa que você pode mudar a implementação interna da lista sem afetar o código que a utiliza.

- **Ocultação de Complexidade:** A implementação de estruturas de dados como listas encadeadas pode ser complexa, envolvendo alocação de memória, gerenciamento de ponteiros e manipulação de nós. O TAD Lista oculta essa complexidade, tornando mais fácil para outros desenvolvedores usar a lista sem se preocupar com os detalhes complicados.

- **Padronização:** O TAD Lista estabelece um conjunto padrão de operações e nomes para trabalhar com listas. Isso torna o código mais consistente e fácil de entender para qualquer desenvolvedor.

- **Facilita a Depuração:** Se ocorrer um erro em uma operação da lista, é mais fácil depurar(Achar o erro) quando você tem uma interface clara e bem definida para a lista. Você pode isolar o problema mais facilmente.

- **Documentação:** O TAD Lista serve como documentação clara das operações suportadas pela lista. Isso ajuda a vocês (desenvolvedores) a entender como usar a lista corretamente.

## Listas Encadeadas Simples

### Descrição lista simples

- Uma lista encadeada simples em C é uma estrutura de dados que consiste em nós ligados em uma sequência, onde cada nó contém dois campos: um campo de dados para armazenar informações e um ponteiro que aponta para o próximo nó na lista.

- Chamos cada elemento da lista de nó, e um conjunto de nós é chamado de lista encadeada.

![Lista encadeada simples](https://github.com/JhoanDev/LinkedList/blob/main/ListaEncadeadaSimples/Img/Lista_encadeada_simples_representacao.png)

**imagem tirada do site:** [SauloArisa](https://www.google.com/url?sa=i&url=https%3A%2F%2Fsaulo.arisa.com.br%2Fwiki%2Findex.php%2FListas_Encadeadas_Simples&psig=AOvVaw2dbQagPe0tVilGhoaTtbFv&ust=1695563841998000&source=images&cd=vfe&opi=89978449&ved=0CBAQjRxqFwoTCKDI3dXxwIEDFQAAAAAdAAAAABAE)
### Estrutura lista simples

```C
struct lista
{
    int info;
    struct lista *prox;
};
```

- **Info:** Representa o dado armazenado na lista, que, no exemplo acima, é um valor inteiro. No entanto, pode ser utilizado para armazenar qualquer tipo de dado, inclusive estruturas (como a struct aluno, por exemplo).

- **Prox:** Armazena o endereço do próximo elemento da lista. Em outras palavras, cada nó mantém um ponteiro para o próximo elemento usando este campo.

### Vantagens lista simples

1. **Alocação Dinâmica de Memória:** Permite a alocação dinâmica de memória, facilitando a adição e remoção de elementos conforme necessário.

2. **Inserção e Exclusão Eficientes:** Inserir ou excluir elementos no início é eficiente, minimizando a necessidade de deslocamento de dados.

3. **Redimensionamento Dinâmico:** A lista pode crescer ou encolher conforme necessário, adequando-se a tamanhos variáveis de dados.

### Desvantagens lista simples

1. **Acesso direto ineficiente:** O acesso a um elemento específico requer percorrer a lista, o que é menos eficiente que arrays para acesso direto por índice.

2. **Gasto de memória extra por elemento:** Cada nó requer espaço extra para o ponteiro, aumentando o consumo de memória em comparação com arrays.

3. **Complexidade de implementação:** Implementar operações pode ser mais complexo devido à gestão de ponteiros e alocação dinâmica de memória.

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
## Listas Encadeadas Duplas

### Descrição lista dupla

Uma lista encadeada dupla é uma estrutura de dados que expande a funcionalidade de uma lista encadeada simples, permitindo que cada nó mantenha referências tanto para o próximo quanto para o nó anterior na sequência. Isso significa que, além de apontar para o próximo nó, cada nó também aponta para o nó anterior, criando uma conexão bidirecional entre os elementos.

A principal diferença entre uma lista encadeada simples e uma lista encadeada dupla é que, em uma lista dupla, você pode percorrer a lista em ambas as direções: do início para o fim e do fim para o início.

As listas encadeadas duplas são uma escolha valiosa quando a flexibilidade e a capacidade de travessia bidirecional são necessárias, mas é importante considerar cuidadosamente as vantagens e desvantagens ao escolher essa estrutura de dados para um determinado problema.

![Lista encadeada duplas](https://github.com/JhoanDev/LinkedList/blob/main/ListaEncadeadaDupla/Img/listaencadeadadupla.png)

**imagem tirada do site:** [SauloArisa](https://www.google.com/url?sa=i&url=https%3A%2F%2Fsaulo.arisa.com.br%2Fwiki%2Findex.php%2FListas_Duplamente_Encadeadas&psig=AOvVaw1W8NZ6mHZglLwEhmvsn0DA&ust=1695564177495000&source=images&cd=vfe&opi=89978449&ved=0CBAQjRxqFwoTCLCx6fXywIEDFQAAAAAdAAAAABAK)

### Estrutura lista dupla

```c
struct lista_dupla
{
    int info;
    struct lista_dupla *prox;
    struct lista_dupla *ant;
};
```

- **Info:** Representa o dado armazenado na lista dupla, que pode ser qualquer tipo de dado, incluindo estruturas ou tipos personalizados.

- **Prox:** Armazena o endereço do próximo elemento na lista dupla, permitindo percorrer a lista da esquerda para a direita.

- **Ant:** Armazena o endereço do elemento anterior na lista dupla, permitindo percorrer a lista da direita para a esquerda.

### Vantagens lista dupla

1. **Travessia Bidirecional:** Uma das principais vantagens das listas encadeadas duplas é a capacidade de percorrer a lista em ambas as direções. Isso permite acesso eficiente tanto do início para o fim quanto do fim para o início, o que pode ser útil em muitos cenários, como a necessidade de encontrar elementos próximos ao final da lista.

2. **Inserção e Exclusão Eficiente em Qualquer Posição:** As listas encadeadas duplas permitem a inserção e exclusão eficiente de elementos em qualquer posição da lista. Isso ocorre porque cada nó mantém referências para os nós anterior e posterior, facilitando a atualização dos ponteiros durante a inserção ou exclusão.

3. **Flexibilidade:** As listas duplas são altamente flexíveis e podem ser usadas em uma variedade de cenários. Elas são especialmente úteis quando a ordem dos elementos é importante e quando operações de inserção e exclusão frequentes são necessárias.

### Desvantagens lista dupla

1. **Consumo de Memória:** Em comparação com algumas outras estruturas de dados, as listas encadeadas duplas podem consumir mais memória devido à necessidade de manter dois ponteiros (um para o próximo nó e outro para o nó anterior) em cada nó da lista. Isso pode ser uma desvantagem em sistemas com restrições de memória.

2. **Complexidade de Implementação:** Implementar e manter listas encadeadas duplas pode ser mais complexo do que listas encadeadas simples ou arrays. Isso ocorre porque é necessário gerenciar os ponteiros de forma mais cuidadosa, garantindo que eles sejam atualizados corretamente durante as operações de inserção e exclusão.

3. **Acesso Direto Ineficiente:** Assim como nas listas encadeadas simples, o acesso direto a um elemento específico em uma lista encadeada dupla requer percorrer a lista, o que pode ser menos eficiente do que o acesso direto por índice em arrays.

### **Algumas Funções da TAD Lista Dupla:**

### listd_cria

- **Descrição:** Cria uma lista encadeada dupla vazia.

```c
Listad *listd_cria(void)
{
    return NULL;
}
```

- **uso:**

```c
Listad *lista = listd_cria();
```

### listd_libera

- **Descrição:** Libera a memória ocupada pela lista encadeada dupla.

```c
void listd_libera(Listad *l)
{
    Listad *p = l;
    while (p != NULL)
    {
        Listad *t = p->prox;
        free(p);
        p = t;
    }
}
```

- **uso:**

```c
listd_libera(lista);
```

### listd_adc

- **Descrição:** Adiciona um novo valor na lista encadeada dupla.

```c
Listad *listd_adc(Listad *l, int v)
{
    Listad *novo = (Listad *)malloc(sizeof(Listad));
    if (novo == NULL)
    {
        printf("[ERRO] Memória insuficiente!");
        exit(1);
    }
    novo->dado = v;
    novo->prox = NULL;
    novo->ant = NULL;

    if (l == NULL)
    {
        return novo;
    }

    Listad *ultimo = l;
    while (ultimo->prox != NULL)
    {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->ant = ultimo;

    return l;
}
```

- **uso:**

```c
lista = listd_adc(lista, 42);
```

### listd_busca

- **Descrição:** Busca por um item na lista encadeada dupla.

```c
Listad *listd_busca(Listad *l, int v)
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
```

- **uso:**

```c
Listad *resultado = listd_busca(42, lista);
```

### listd_retira

- **Descrição:** Remove um nó da lista encadeada dupla.

```c
Listad *listd_retira(Listad *l, int v)
{
    Listad *p = listd_busca(l, v);

    if (p == NULL)
    {
        return l; // não achou
    }

    // Remove o elemento
    if (l == p) // Testa se é o primeiro elemento
    {
        l = p->prox;
        if (p->prox != NULL)
        {
            p->prox->ant = NULL;
        }
    }
    else
    {
        p->ant->prox = p->prox; // Remove o do meio
        if (p->prox != NULL)
        {
            p->prox->ant = p->ant;
        }
    }
    free(p);
    return l;
}
```

- **uso:**

```c
lista = listd_retira(lista, 42);
```

### listd_vazia

- **Descrição:** Verifica se a lista encadeada dupla está vazia.

```c
int listd_vazia(Listad *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}
```

- **uso:**

```c
if (listd_vazia(lista))
{
    printf("A lista está vazia.\n");
}
```

### listd_imprime

- **Descrição:** Imprime o valor de todos os elementos da lista encadeada dupla.

```c
void listd_imprime(Listad *l)
{
    Listad *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("Dado = %d\n", p->dado);
    }
}
```

- **uso:**

```c
listd_imprime(lista);
```