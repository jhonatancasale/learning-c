#!/bin/bash

for i in $(find -name Makefile);
do
  echo "$(pwd)" "-> " "$(dirname $i)"
  cd `dirname $i`
  make clean
  cd -
done
