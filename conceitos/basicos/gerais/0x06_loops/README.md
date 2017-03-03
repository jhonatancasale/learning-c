# Loops

tl;dr
- [O que são loops?](#do-que-se-trata-e-para-que-serve)
- [Statement](#statement)
- [for](#for)
- [while](#while)
- [do while](#do-while)
- [Comparando os loops](#comparação-dos-casos-de-uso)

## // Do que se trata e para que serve?
Vez por outra precisamos repetir determinadas tarefas por n de vezes ou
indefinidamente, fazemos uso então de estruturas de repetição ou _loops_.

Pensando que os casos de uso de loops podem ser categorizados em **2** grandes
categorias, uma delas com 2 subcategorias:
- loops **infinitos**
- loops **finitos**
  - numero **definido** de iterações
  - numero **indefinido** de iterações

Dito isso, como **C** implementa essas ideias? Basicamente existem 3 maneiras;
mas no final do dia temos apenas **2** que se destacam, a terceira é um caso
particular de uma delas. São:
- **for**
- **while**
- **do while**

Que definem diferentes maneiras de se executar um determinado conjunto de
instruções que simplificadamente chamaremos de **&lt;statement&gt;**.


#### &lt;statement&gt;
Uma forma genérica de dizer que o corpo do laço, ou seja, os comandos que
efetivamente serão executados pode ser da forma:
* **{** &nbsp;   /\* uma ou mais instruções \*/ &nbsp; **}**
* /\* somente uma instrução \*/
* **;**


## for
### Quando usar?
Em geral, se *prefere* usar essa estrutura de repetição quando sabemos de
alguma forma o numero de iterações, o que acontece frequentemente quando
iteramos do valor **a** até o valor **b** com um **passo** conhecido.

### Sintax
> for ( {&lt;expression&gt; }? ; {&lt;expression&gt;}? ; {&lt;expression}? ) &lt;statement&gt;

Simplificando, temos **3** blocos separados por **;**
> for ( initializations; test_evaluation ; updates ) &lt;statement&gt;

### Exemplos de uso: `for` loop
```c
for ( int i = 0, n = strlen(str); i < n; i++ ) {
  printf ("%c\n", str[i]);
}
```

Que percorre a string `str` imprimindo na tela uma letra por linha.

#### Entendendo melhor o comportamento dos blocos
No bloco de *initializations* definimos **2** variáveis, sendo uma a variável
de controle do loop e outra como sendo a condição de parada, uma pequena
otimização para não chamar a função `strlen()` a cada iteração, assumindo que o
comprimento da palavra não vai mudar ao longo das iterações.

No bloco de *test_evaluation* comparamos a variável `i` com a variável `n` que
armazena o tamanho da string `str` e caso o test seja avaliado como `false` (ou
zero) o processo termina.

E por fim no bloco de *updates* incrementamos a variável de controle.

#### A ordem de execução desses blocos
1. *initializations*
2. Enquanto *test_evaluation* resultar `true`
  1. Executar o bloco de &lt;statement&gt;
  2. Realizar os *updates*
  3. Voltar para o *test_evaluation*

No caso anterior o bloco &lt;statement&gt; foi encapsulado por `{}`, podemos
omitir estes delimitadores sempre que o bloco for composto de apenas **1**
instrução. Exemplo.
```c
for ( int i = 0, n = strlen(str); i < n; i++ )
  printf ("%c", toupper(str[i]));
```
#### Exemplos não tão usuais
E por fim, quando o bloco de &lt;statement&gt; é formado por apenas **;**, de
alguma forma estamos computando algo de interesse *no* loop, como nos exemplos.

// Can I calculate the sum of a range of numbers?
```c
int sum = 0;

for ( int i = 1; i <= 100; sum += i++ );

printf("Sum from 0 to 100: %i\n\n", sum);
```
// Can I calculate fact within a loop?
```c
int fat = 1;

for ( int i = 1; i <= 5; fat *= i++ );

printf("factorial(5):%i\n", fat);
```

Que respectivamente computam a soma dos inteiros de [0,100] e o fatorial de 5.


## while
### Quando usar?
Em geral se *prefere* usar essa estrutura de repetição quando não sabemos
*a priori* o numero de vezes que iremos iterar, seja o caso dos loops infinitos
ou no caso em que precisamos esperar por alguma determinada condição acontecer.

### Sintax
> while ( &lt;expression&gt; ) &lt;statement&gt;

Simplificando
> while ( condition ) &lt;statement&gt;

O loop `while` executa enquanto o bloco *condition* é avaliado como `true`.

### Exemplos de uso: `while` loop
Reimplementando os 2 primeiros exemplos do loop `for`

```c
int i = 0;
while ( str[i] != '\0' ) {
  printf ("%c\n", str[i]);
  i++;
}
```

Onde podemos verificar a presença dos mesmos componentes, mas de uma forma mais
desagrupada talvez. **Importante** lembrar sempre que de alguma forma a
variável de controle do loop precisa ser atualizada.

```c
i = 0;
while ( str[i] != '\0' )
  printf ("%c", toupper(str[i++]));
```

Notemos os `{}` opcionais nos casos em que o bloco de &lt;statement&gt; é
formado por apenas uma única instrução.

E por fim, quando queremos executar indefinidamente.

```c
while ( 1 ) {
  /* comandos */
}
```

#### Exemplos não tão usuais
Vale ressaltar o conceito de *magic numbers*, que é a maneira de denominar
qualquer ocorrência *mandrakiana* de algum numero no código, via de regra esse
número não tem uma explicação racional de rápida inferência e muito menos um
comentário ilustrativo e amigável para explicar.

Dito isso, temos a construção que serve para travar a execução do programa em
um determinado ponto, o que eventualmente pode ser exatamente o que se quer
executar.

```c
while ( 1 );
```

No caso acima o programa fica travado indefinidamente, ou no caso abaixo o
programa trava enquanto o retorno da função for diferente de zero {a.k.a. true}
```c
while ( foo() );
```

## do while
### Quando usar?
Como dito no início, no final do dia, **C** acaba por oferecer **2** formas de
loop, este aqui (como o nome já sugere) é um caso particular do loop `while`, a
diferença esta no ponto em que este loop **garante ao menos 1** execução do
bloco &lt;statement&gt;. Sim, é situacional e não acrescenta efetivamente
nenhuma nova funcionalidade.

> do &lt;statement&gt; while ( &lt;expression&gt; ) ;

### Exemplos de uso: `do while` loop
```c
do {
  printf ("Choose one:\n");
  printf ("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: ");
  scanf("%i", &value);
} while ( value <= 0 || value > 10 );
```

Que repete indefinidamente até que o usuário gentilmente forneça um numero
inteiro dentro as opções sugeridas.

E assim como nos outros casos, os `{}` podem ser omitidos nos casos em que o
bloco de &lt;statement&gt; é apenas uma instrução.

```c
do value = read_value();
while ( value <= 0 || value > 10 );
```

Onde `read_value()` é uma função que executa comportamento de entrada de dados
do exemplo anterior, retornando o valor lido no `scanf`.


## Comparação dos casos de uso
| Loop      | Infinito | Finito e indeterminado | Finito e determinado |
| :-------: | -------- | ---------------------- | -------------------- |
| for       | for ( ;; ) | for ( ; test_true; ) | for ( int i = 10; i > 0; i-- )
| while     | while (1) | while ( test_true ) | int i = 10;<br>while ( i > 0 ) {<br>&nbsp;&nbsp;// ... <br>&nbsp;&nbsp;i--;<br>}
| do while  | do {<br>&nbsp;&nbsp;// ... <br>} while ( 1 ); | do {<br>&nbsp;&nbsp;// ... <br>} while ( test_true ) | int i = 10;<br>do {<br>&nbsp;&nbsp;//<br>&nbsp;&nbsp;i--;<br>} while ( i > 0 ); |
