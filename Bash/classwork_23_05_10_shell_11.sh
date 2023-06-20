#!/bin/bash
sum=0
finale=0
read -p "Please enter your multiplier:" multiplier
for it in "$@"; do 
        sum=d$(($it+$sum)) 
    done
    finale=$(($sum*$multiplier))
    echo "Sum of args($sum) multiplied by multiplier ($multiplier) is = $finale"