# printf
#### Protótipo

> int printf( const char *format, ... );

  Via de regra o primeiro programa que tendemos a fazer quando estamos
estudando uma linguágem é o clássico _Hello World_, em C isso pode ser feito
como segue:
```c
  printf("Hello World!");
```

  Neste caso a função `printf` recebeu apenas **1** parâmetro, mas esta função
tem a capacidade de lidar com multiplos parâmetros, o protocolo de
comportamento usado é que o usuário instrui a função `printf` com uma string
formatadora de saída, seguida de **0** ou **mais** parâmetros que serão formatados
na `stdout` (saída padrão).

#### Formatadores de Saída
  Existe uma quantidade relativamente grande de sabores de formatadores, os 
mais principais.

##### Formatadores mais usádos

| String | Usado para |
| ------ | :--------: |
| %d | Inteiros (int) |
| %f | Reais (float) |
| %c | Caracteres (char) |
| %s | Strings (char[]) |

  O `\n` é usado para instruir a função `printf` para pular uma linha e ir para 
o começo dessa nova linha.
```c
  int i = 0;
  float f = 8.9;

  printf( "%d\n", i);
  printf( "%f\n", f);

  char c = 'f';
  char s[] = "This is a test";

  printf( "%c\n", c);
  printf( "%s\n", s);
```
  Apesr dos muitos possíveis formatadores de saída, a maior parte do tempo o 
programador consegue se virar muito mais que bem com apenas esse casos.

#### Valor de retorno
  A função `printf` retorna um `int` de quantos caracters foram efetivamente
enviados para `stdout`, isso pode ser interessante quando se esta preocupado em
manter alguma coêrencia na saída mantendo o numero de caracteres impressos
constante, mas via de regra o retorno dessa função é ignorado.

#### Usando operadores ternários para simular bools
  C é uma linguagem que nativamente não possui o tipo de dado `boolean`, o que
na prática acontece é que em alguns casos para melhor legibidade, queremos
exibir algo como `false` ou `true` na tela, podemos usar ternarios dentro do
printf neste caso.
```c
  int condition = 1;

  printf( "%s\n", (condition) ? "true" : "false" );
```

Que pode ser uma alternativa para a forma

```c
  int condition = 1;

  if (condition)
    printf( "true\n");
  else
    printf( "false\n");
  ```

#### Alterando o comportamento da saída durante a execução
  Um ponto que nem sempre nos atentamos é que o primeiro parâmentro usado no
printf é uma `string`, ou seja, uma variável.
```c
  float value = 9.87657;
  char format[] = "%.2f";

  printf(format, value);
```

#### Debug
  Como vez por outra precisamos fazer um *debug orientado a printf*, não que
seja a melhor prática a ser adotada, existem ferramentas específicas para essa
funcionalidade, mas para casos simples em que se quer imprimir em tela o nome
do arquivo e a linha onde o programa esta executando no momento

```c
  printf("%s:%d", __FILE__, __LINE__);
```

#### Conclusões
  O objetivo aqui era apresentar o básico da função e alguns usos situacionais
e interessantes que podem ajudar durante a prática da programação. Códigos
prova de conceito podem ser encontrados [aqui](#).
