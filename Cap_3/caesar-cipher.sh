#!/bin/bash

if [ $# -eq 0 ]; then
   echo "
  Usage:
       caesar-cipher.sh  <text>"
else 
   for((i=0;i<=25;i++))
   do
    text="$1"
    ciphertext=$(rotix -t "$text" -L -r $i)
    echo "Key: $i -- $ciphertext"
   done
fi
