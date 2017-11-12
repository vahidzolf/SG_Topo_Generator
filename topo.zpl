set N := {read "n.txt" as "<1n>"};
set R := {read "r.txt" as "<1n>"};

param C[N*R] := read "c.txt" as "<1n,2n> 3n";

var X[N*R] binary;
var Z[R] binary;

minimize f: sum <r> in R: Z[r];

subto const1: forall <r> in R: forall <n> in N: X[n,r] <= Z[r]*C[n,r];
subto const2: forall <n> in N: sum <r> in R: X[n,r] == 1; 
