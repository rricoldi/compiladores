#!/bin/bash
make
for i in $(seq 1 5); do
    ./sintatico < tests/entrada_0$i.txt > saida_0$i.txt
    DIFF=$(diff tests/saida_0$i.txt saida_0$i.txt)
    if [ "$DIFF" != "" ]
    then
        echo "test $i failed"
    else
        echo "test $i succeed"
    fi
    rm saida_0$i.txt
done
make clean