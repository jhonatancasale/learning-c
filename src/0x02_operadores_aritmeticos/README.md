# Operadores aritméticos

  Agora que já vimos alguns dos tipos de variáveis mais usados, seguimos com
possíveis operações aritméticas que podemos executar com estes tipos, as
tradicionais:

Operação      | Operador | Exemplo
------------- | -------- | -------
Soma          | +        | a + b
Subtração     | -        | a - b
Multiplicação | *        | a * b
Divisão       | /        | a / b

  Outro operador muito útil é o de _resto_ da divisão **%**

------------- -------- -------
Operação      Operador Exemplo
------------- -------- -------
Resto         %        a % b
------------- -------- -------

  Alguns casos particulares, recorrentemente nos deparamos com construções do
tipo:
```c
  a = a + b;
```
  Para este tipo de construção podemos encurtar a notação usando apenas **+=**
ficando
```c
  a += b;
```
  O operador pode ser qualquer um dos já mencionados [+,-,*,/,%] podemos então
encontrar essas construções

-------------- ---------------
Forma resumida Forma expandida
-------------- ---------------
a += b         a = a + b
a -= b         a = a - b
a *= b         a = a * b
a /= b         a = a / b
a %= b         a = a % b
-------------- ---------------

E um último caso particular é o incremento simples:
```c
  a += 1;
```

Que pode ser resumido pelo operador **++** que pode ser _pré_ ou _pós_ fixado:

-------- ---------------------- ------------------------
Operador Semântica              Exemplo
-------- ---------------------- ------------------------
++a      Incremente primeiro    b = 3;
         depois use o novo      a = ++b
         valor                  //a = 4, b = 4
a++      Use o valor antigo     b = 3
         depois incremente      a = b++; 
                                // a = 3, b = 4
-------- ---------------------- ------------------------

  Neste exemplo usamos o operador de _incremento_ mas o mesmo é válido para o
operador de _decremento_ **--**.

**~Jhonatan**
