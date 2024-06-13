#!/bin/bash

# Cria os arquivos com make e move os tempos
do()
{
    pushd $1
    make all
    mv *.txt ../
    popd
}

do("Linked Lists")
do(Trees)
