# Hello World | README #

Esta aplicação é a mais famosa de todos os programadores, talvez por ser a mais
simples. A única tarefa é simplesmente imprimir uma mensagem (string) na saída
de texto padrão (STDOUT) do computador. Mas no caso da linguagem C, esta
simples ação consegue apresentar alguns conceitos **interessantes** e
necessários mais pra frente.

Neste exemplo simples:
```c
#include <stdio.h>

int main (void)
{
  printf ("Hello world\n");

  return (0);
}
```

Podemos notar algumas coisas *estranhas*, primeiro de tudo, devemos lembrar do
objetivo desse código, **para que serve esse código?** -- *Imprimir na tela do
usuário a mensagem "Hello world"*, ok.

Bacana, vimos este mensagem na linha 5 no meio de um monte de outras coisas...

C usa o conceito de funções, uma função é uma abstração que encapsula
comportamentos desejados, e segundo o principio do KISS, cada função deve fazer
"uma" coisa, mas muito bem, nesse caso, a função que usamos para imprimir a
mensagem na tela se chama **printf** que **formata e imprime dados**, esse é o
núcleo funcional do programa.

Mas para que essa funcionalidade **funcione** precisamos de alguns recursos
adicionais, como por exemplo, na primeira linha do exemplo, vemos a diretiva de
**#include <stdio.h>**, que instrui ao compilador (C assim como C++ são
compiladas) que incluía a biblioteca de I/O do sistema, nesta biblioteca é que
esta definida a função **printf**.

**int main (void)** é a função principal do nosso programa, é ela que o Sistema
Operacional irá executar quando rodarmos esse programa, essa sintaxe (veremos
detalhes mais a frente) indica que o **tipo** de retorno dessa função é
inteiro, ou seja, um numero inteiro será retornado ao final da execução para
quem invocou nosso programa. O nome da função é **main** e não recebe
parâmetros de entrada, indicado pelo **(void)**

A seguir temos a linha que visualmente **faz alguma coisa** e por fim a ultima
diretiva de **return (0)**, que é justamente, o **inteiro** que esta sendo
retornado para o SO.

Pois bem, esse é o primeiro exemplo que apesar de ser muito simples, aborda
algumas temáticas recorrentes, como o conceito de funções, bibliotecas,
parâmetros de entrada, valores de retorno e chamadas do SO.

#### Conclusão ####
Com uma simples aplicação pudemos entender um pouco mais como funciona a
mecânica dos programas em C e com poucas linhas de código já nos familiarizamos
mais com alguns conceitos que estarão presentes ao longo do caminho e dos
outros exemplos.

**~Jhonatan**
