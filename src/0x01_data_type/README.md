# Principais tipos de dados

Pois bem, C possui alguns tipos de dados para manipulação e armazenamento de
informações, estes são alguns dos principais tipos:
```c
//[...]
  int var = 1;

  float fl_var = 1.1;

  double dl_var = 1.2;

  char ch_var = 'a';
//[...]
```

###### Saída do programa data_type_example_00
> 1 <br>
> 1.100000 <br>
> 1.200000 <br>
> a <br>

É importante notar que C é uma linguagem fortemente tipada, precisamos
explicitamente declarar o **tipo** da variável, na forma geral:

> type_name var_name [= initial_value];

* type_name: Pode ser um dos mencionados anteriormente [int, float, double,
    char] ou qualquer outro tipo (iremos ver alguns outros exemplos e como
    criar nossos próprios tipos mais adiante)

    **Onde**:
    - **int**: declara a variável como do tipo inteiro
    - **float**, **double**: declara a variável como sendo do tipo ponto flutuante,
        podendo assim receber valores decimais.
    - **char**: declara a variável como sendo do tipo caractere, podendo armazenar
        um e somente um caractere por vez
* var_name: Nome da variável que queremos definir, este nome precisa começar
    com uma letra ou _ , e via de regra, não aceita caracteres especiais
* [= initial_value]: Este parâmetro é opcional, e irá atribuir este valor logo
    após criada a variável em memória, é considerado uma boa prática
    inicializar variáveis.

#### Conclusão ####
  Como iremos ver mais para frente, em C, apesar de existir tipos
pré-definidos, podemos declarar nossos próprios tipos, assim como podemos fazer
uso de um recurso chamado _typecasting_, que consiste em avaliar o valor de uma
variável como sendo de um outro determinado tipo.

**~Jhonatan**
