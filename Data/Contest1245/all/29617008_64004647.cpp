#include <bits/stdc++.h>


long long DP(int n,int m) {
    ++n,++m;
    std::vector<int> bn,bm;
    while(n) {
        bn.push_back(n%2);
        n/=2;
    }
    while(m) {
        bm.push_back(m%2);
        m/=2;
    }
    int len=std::max(bn.size(),bm.size());
    bn.resize(len);
    bm.resize(len);
    static long long f[40][2][2];
    memset(f,0,sizeof(f));
    f[len][1][1]=1;
    for(int i=len-1;i>=0;--i)
        for(int sn=0;sn<2;++sn)
            for(int sm=0;sm<2;++sm) {
                if(!sn || bn[i])
                    f[i][sn][sm && (bm[i]==0)]+=f[i+1][sn][sm];
                if(!sm || bm[i])
                    f[i][sn && (bn[i]==0)][sm]+=f[i+1][sn][sm];
                f[i][sn && (bn[i]==0)][sm && (bm[i]==0)]+=f[i+1][sn][sm];
            }
    return f[0][0][0];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    //freopen("in1.txt","r",stdin);
    int T;std::cin>>T;
    while(T--) {
        int l,r;std::cin>>l>>r;
        std::cout<<DP(r,r)-2*DP(l-1,r)+DP(l-1,l-1)<<'\n';
    }
	return 0;
}
