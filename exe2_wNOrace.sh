#!/bin/sh

#  exe2_wNOrace.sh
#  exe2
#
#  Created by НУРИЯ on 9/17/20.
#  Copyright © 2020 НУРИЯ. All rights reserved.
#creating file with numbers(no race)
if test ! -f exe2.txt
then
echo 0 > exe2.txt  //creating file
fi
if ln exe2.txt exe2.txt.lock
then
i=0
while [ $i -le 999 ] # append numbers to the file 1000 times f
do
n='tail-1 exe2.txt'
expr $n + 1 >>exe2.txt
done
#unlock
rm exe2.txt.lock
fi

