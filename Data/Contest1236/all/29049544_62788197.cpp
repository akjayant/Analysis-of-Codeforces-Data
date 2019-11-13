#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define llg     long long

#define MOD     1000000007

llg fastPow(llg base, llg exp) {
    if (exp == 0) return 1;
    llg v = fastPow(base, exp/2)%MOD;
    if (exp&1) return (((v*v)%MOD)*base)%MOD;
    return ((v*v)%MOD);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    llg N, M;   input >> N >> M;
    output << fastPow((fastPow(2, M)-1+MOD)%MOD, N);

    return 0;
}
