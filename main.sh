#!/bin/bash

# Cria os arquivos com make e move os tempos
do_test()
{
    pushd "$1"
    make all &&
    mv *.csv ../
    popd
}

do_test "Linked Lists" &&
do_test "Trees"
