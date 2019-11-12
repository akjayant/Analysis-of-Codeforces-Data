#include <bits/stdc++.h>

const int XN=1e2+11;
template <class T>
bool Enlarge(T &a,T const &b) {
    return a<b?a=b,1:0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int T;std::cin>>T;
    while(T--) {
        int a,b,c;std::cin>>a>>b>>c;
        /*int res=0;
        while(a>=1 && b>=2) {
            a--;b-=2;
            res+=3;
        }
        while(b>=1 && c>=2) {
            b--;c-=2;
            res+=3;
        }
        std::cout<<res<<'\n';
        */
        static int f[XN][XN][XN];
        memset(f,0,sizeof(f));
        f[0][0][0]=0;
        for(int i=0;i<=a;++i)
            for(int j=0;j<=b;++j)
                for(int k=0;k<=c;++k) {
                    f[i][j][k]=0;
                    if(i>=1 && j>=2)
                        Enlarge(f[i][j][k],f[i-1][j-2][k]+3);
                    if(j>=1 && k>=2)
                        Enlarge(f[i][j][k],f[i][j-1][k-2]+3);
                }
        std::cout<<f[a][b][c]<<'\n';
    }
	return 0;
}

