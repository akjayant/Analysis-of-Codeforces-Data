#include <bits/stdc++.h>

const int XN=1e5+11,P=1e9+7;

void M(int &x) {
    ((x>=P) && (x-=P)) || ((x<0) && (x+=P));
}

int Pow(long long base,int v) {
    long long res=1;
    for(;v;v>>=1,(base*=base)%=P)
        if(v&1)
            (res*=base)%=P;
    return res;
}

int main() {
    //freopen("input","r",stdin);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    static int f[XN];
    f[1]=2;f[2]=4;
    for(int i=3;i<XN;++i)
        M(f[i]=f[i-2]+f[i-1]);
    int n,m;std::cin>>n>>m;
    if(n>m)
        std::swap(n,m);
    if(n==1)
        std::cout<<f[m]<<'\n';
    else {
        int Ans=(f[m]+f[n]-2)%P;
        M(Ans);
        std::cout<<Ans<<'\n';
    }
	return 0;
}

