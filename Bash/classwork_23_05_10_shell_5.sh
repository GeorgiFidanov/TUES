#!/bin/bash
sum=0
for it in "$@"; do 
        sum=$(($it+$sum)) 
    done
    echo $sum