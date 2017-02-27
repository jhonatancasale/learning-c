#!/bin/bash

# the idea
# * listar todos os diretorios que tenham um `Makefile`
# cd para esse cara
# rodar o clean
# voltar para onde estava

for i in $(find -name Makefile);
do
  echo "$i"
done
