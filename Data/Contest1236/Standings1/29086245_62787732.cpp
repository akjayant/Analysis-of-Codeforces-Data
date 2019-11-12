#include <bits/stdc++.h>

const int P=1e9+7;

int Pow(long long base,int v) {
    long long res=1;
    if(base<0)
        base+=P;
    for(;v;v>>=1,(base*=base)%=P)
        if(v&1)
            (res*=base)%=P;
    return res;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int n,m;std::cin>>n>>m;
    std::cout<<Pow(Pow(2,m)-1,n)<<'\n';
	return 0;
}

