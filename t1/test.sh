#!/bin/bash
make
for i in $(seq 0 9); do
    ./pascal < tests/tc0$i.pas > saida_0$i.txt
    DIFF=$(diff tests/saida_0$i.txt saida_0$i.txt)
    if [ "$DIFF" != "" ]
    then
        echo "❌ test $i failed"
    else
        echo "✔️ test $i succeeded"
    fi
    rm saida_0$i.txt
done
make clean