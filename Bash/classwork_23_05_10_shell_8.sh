#!/bin/bash
#2) Да се напише shell скрипт, който приема точно един параметър и проверява дали
#подаденият му параметър се състои само от букви и цифри.

str="$1"
pattern="^[0-9 a-z A-Z]*$"
var="$(echo $str | grep pattern |wc -l)"
if [ $var -eq 0 ]; then
    echo Yes
else 
    echo No
fi