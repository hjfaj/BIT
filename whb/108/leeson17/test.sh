#!/usr/bin/bash

function myfun()
{
    cnt=1
    while [ $cnt -le 10 ]
    do
        echo "hello $cnt"
        let cnt++
    done
}

echo "hello 1"
echo "hello 1"
echo "hello 1"
echo "hello 1"
echo "hello 1"
echo "hello 1"
echo "hello 1"
ls -a -l
myfun
