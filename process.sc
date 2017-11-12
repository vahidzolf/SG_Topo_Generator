#!/bin/sh
> fx.txt
> out.txt

#scip -f topo.zpl > log.txt

grep "^X#" log.txt > xfile.txt
sed -i 's/#/ /g' xfile.txt
sed -i 's/1 \t(obj:0)/ /g' xfile.txt

while read X1 X2 X3
do
	echo $X3 >> fx.txt
done < xfile.txt

#sort fx.txt | uniq -c >> out.txt 
