#!/bin/sh
> plc.txt
> gfile.txt

#scip -f topo.zpl > log.txt

grep "^X#" log.txt > gfile.txt
sed -i 's/#/ /g' gfile.txt
sed -i 's/1 \t(obj:0)/ /g' gfile.txt

while read X1 X2 X3
do
	echo $X2 $X3 >> plc.txt
done < gfile.txt

cp plc.txt ../
