# STAT-distribtion-library-C-
This library includes 6 kinds of useful distribution and some helper functions for STAT learning purpose

distrubution:

1. discrete uniform: DU
2. binomial: Bin
3. negative binomial: NB
4. Geometric: Geo
5. hypergeometric: HG
6. Poisson: Poisson

helper:

1. sum(int, int, double(*)(int))

2. permute(int, int)

3. fact(int)

4. choose(int, int)

constant:

1. MATH_e

functions for each distribution:

1. pf
2. cdf


way to use:

step 1:
create RV object: RV a;

step 2:
declare distribution: a.set_Bin(10, 0.5);

step 3:
call the pf(cdf): cout<<info(a)->pf(5);

step 4:
destroy the distribution attribute of the object (so that use can bind it to other distribution):
a.destroy();

p.s: minimum RV memory require: 8bypes;
     minimum distribution memory require: 4 bytes;




