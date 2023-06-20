#!/bin/bash
stat $(find) -c "%h %n" |
sort -n | head -n 5 |
cut -f 2 -d ' '