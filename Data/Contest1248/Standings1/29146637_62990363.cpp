#include<bits/stdc++.h>

constexpr auto MOD = (long long)1e9+7;
constexpr auto MAXN = 100050;
constexpr auto MAXM = MAXN;

long long D[MAXN];

signed main(void)
{
    int totLine,totList,lim;
    long long tot = -1;

    std::cin>>totLine>>totList; lim = std::max(totList,totLine);

    D[0] = D[1] = 1;
    for(int i=2;i<=lim;i++) D[i] = (D[i-1] + D[i-2]) % MOD;

    (tot += D[totLine] + D[totList]) %= MOD;

    std::cout<<(tot<<1)%MOD<<std::endl;
    
    return 0;
}
