#!/bin/sh
> fx.txt
> out.txt
> xs.txt
> ys.txt
> c.txt
> r.txt
> log.txt
> xfile.txt
> hop.txt

#$1 is number of nodes 
echo 'generating base points'
./blue $1 38
echo '...done'
#$2 is the max steps btw a plc and wireless node 
echo 'manuipulate points'
./dgwp.out $1 $2
echo '...done'

echo $2 >> hop.txt

echo 'running model for Wireless nodes'
scip -f topo.zpl > log.txt
echo '...done'

./process.sc 

./dup

./ToWho.sc 

cp out.txt xs.txt ys.txt hop.txt ../
cp out.txt xs.txt ys.txt ../files/
cp out.txt xs.txt ys.txt ../GC/

