#!/bin/sh

#  exe2_wRace.sh
#  exe2
#
#  Created by НУРИЯ on 9/17/20.
#  Copyright © 2020 НУРИЯ. All rights reserved.
if test ! -f exe2_race.txt
then
    echo 0 > exe2_race.txt #creating file with numbers
fi
i=0
while [ $i -le 999 ] #appending numbers to the file 1000 times
do
    n='tail -1 exe2_race.txt'   #reading the last number in the file, adding 1 to it,
    expr $n + 1 >> exe2_race.txt   #and then appending it to the file
done

