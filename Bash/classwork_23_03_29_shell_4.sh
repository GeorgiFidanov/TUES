#!/bin/bash
stat  -c "%h %Y %i" $(find ~)|
sort -k 2 -n -t ' '|
cut -d ' ' -f 3 |
head -n 1 



10 14 15 18 20 23 
