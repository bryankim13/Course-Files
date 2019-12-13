#!/bin/bash

# Bryan Kim
# bjk3yf
# 10/22/19
# averagetime.sh

echo "Dictionary File: "
read dict
echo "Grid File: "
read grid
a=`./a.out $dict $grid | tail -1`
b=`./a.out $dict $grid | tail -1`
c=`./a.out $dict $grid | tail -1`
d=`./a.out $dict $grid | tail -1`
e=`./a.out $dict $grid | tail -1`
f=$((a+b+c+d+e))
g=$((f/5))
echo $g