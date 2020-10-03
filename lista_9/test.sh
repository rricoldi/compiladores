#!/bin/bash
make
for i in $(seq 1 6); do
    ./l9e1 < testes/entrada_0$i.txt > saida_0$i.txt
    DIFF=$(diff testes/saida_0$i.txt saida_0$i.txt)
    if [ "$DIFF" != "" ]
    then
        echo "test $i failed"
    else
        echo "test $i succeed"
    fi
    # rm saida_0$i.txt
done
make clean