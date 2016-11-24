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

> var_type var_name [= initial_value];

* type_name: Pode ser um dos mencionados anteriormente [int, float, double,
    char] ou qualquer outro tipo (iremos ver alguns outros exemplos e como
    criar nossos próprios tipos mais adiante)

    **Onde**:
    - **int**: declara a variável como do tipo inteiro
    - **float**, **double**: declara a variável como sendo do tipo ponto
      flutuante, podendo assim receber valores decimais.
    - **char**: declara a variável como sendo do tipo caractere, podendo 
      armazenar um e somente um caractere por vez
* var_name: Nome da variável que queremos definir, este nome precisa começar
    com uma letra ou _ , e via de regra, não aceita caracteres especiais
* [= initial_value]: Este parâmetro é opcional, e irá atribuir este valor logo
    após criada a variável em memória, é considerado uma boa prática
    inicializar variáveis.

#### Typecast
  Vez por outra queremos interpretar uma variável de um tipo, como sendo de
outro, isso pode parecer estranho mas é um tanto recorrente em C, (isso que dá
as coisas serem tipadas :) ) principalmente para alocação dinâmica e passagem
de alguns parâmetros de forma mais genérica. 
  Para isso, se faz uso de uma estrutura do _typecast_
```c
  int a = 10, b = 3;
  float c = (float)a / b;
  printf ( "%f\n", c ); // 3.333333
```
  Esta construção segue na forma:
> (target_type)(actual_value)

* Onde  _target_type_ representa o tipo pelo qual queremos interpretar o valor
 contido em _actual_value_

#### void
  Podemos pensar _void_ como sendo um tipo _vazio_, isso é, pode ser qualquer
coisa, assim como pode não significar nada, dado que, nada é um caso particular
de qualquer coisa, hummm, ok! Esse conceito fica mais evidente quando
usamos _funções_, _ponteiros_ e _ponteiros para funções_, por enquanto, é
interessante ter em mente que se trata apenas de um tipo genérico.

#### Conclusão ####
  Como iremos ver mais para frente, em C, apesar de existir tipos
pré-definidos, podemos declarar nossos próprios tipos.

**~Jhonatan**
