# Hello World | README #

Esta aplicação é a mais famosa de todos os programadores. A única tarefa é
simplesmente imprimir uma mensagem (string) na saída de texto padrão (STDOUT)
do computador. Mas no caso da linguagem C, esta simples ação apresenta algum
overhead de primeira vista.

Neste exemplo simples:
```c
#include <stdio.h>

int main (void) {
  printf ("Hello world\n");
}
```

Podemos notar algumas coisas *estranhas*, primeiro de tudo, devemos lembrar do
objetivo desse código, **para que serve esse código?** -- *Imprimir na tela do
usuário a mensagem "Hello world"*, ok!

Bacana, vimos este mensagem na linha [4](https://github.com/jhonatancasale/learning-c/blob/master/conceitos/basicos/gerais/0x00_hello_world/hello_world.c) no meio de um monte de outras coisas...

C usa o conceito de funções, uma função é uma abstração que encapsula
comportamentos desejados, nesse caso, **printf** que **formata e imprime
dados**, o `\n` do final indica para pular para a próxima linha, esse é o
núcleo funcional do programa.

Mas para que essa funcionalidade **funcione** precisamos de alguns recursos
adicionais, como por exemplo, na primeira linha do exemplo, vemos a diretiva de
**#include <stdio.h>**, que instrui o preprocessador (sim, C, assim como C++ é
uma linguagem compilada) que inclua a biblioteca de I/O do sistema.

**int main (void)** é a função principal do nosso programa e é ela que o
Sistema Operacional (SO) irá executar quando esse programa executar, essa
sintaxe indica que o **tipo** de retorno dessa função é inteiro, ou seja, um
numero inteiro será retornado ao final da execução para quem invocou nosso
programa, indicado pelo **(int)**. O nome da função é **main** e não recebe
parâmetros de entrada, indicado pelo **(void)**.

A seguir temos a linha que visualmente **faz alguma coisa** e o fim do
programa. Implicitamente estamos retornando o valor **0** para o SO indicando
que nada de errado aconteceu com nosso programa e que ele finalizou com
sucesso.

Pois bem, esse é o primeiro exemplo que apesar de ser muito simples, aborda
algumas temáticas recorrentes, como o conceito de funções, bibliotecas,
parâmetros de entrada, valores de retorno e chamadas do SO.

#### Conclusão ####
Com uma simples aplicação pudemos entender um pouco mais como funciona a
mecânica dos programas em C e com poucas linhas de código já nos familiarizamos
mais com alguns conceitos que estarão presentes ao longo do caminho e dos
outros exemplos.

**~Jhonatan**
