#!/bin/bash
for i in $(seq 1 9); do
    ./l6e1 < testes/entrada_0$i.txt > saida_0$i.txt
    DIFF=$(diff testes/saida_0$i.txt saida_0$i.txt)
    if [ "$DIFF" != "" ]
    then
        echo "test $i failed"
    else
        echo "test $i succed"
    fi
    rm saida_0$i.txt
done

for i in $(seq 10 20); do
    ./l6e1 < testes/entrada_$i.txt > saida_$i.txt
    DIFF=$(diff testes/saida_$i.txt saida_$i.txt)
    if [ "$DIFF" != "" ]
    then
        echo "test $i failed"
    else
        echo "test $i succed"
    fi
    rm saida_$i.txt
done