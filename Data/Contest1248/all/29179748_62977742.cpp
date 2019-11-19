#include <bits/stdc++.h>

const int XN=1e5+11;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int T;std::cin>>T;
    while(T--) {
        static int a[XN],b[XN];
        int n,m;
        std::cin>>n;
        int cnt[2]={0};
        for(int i=1;i<=n;++i) {
            std::cin>>a[i];
            cnt[a[i]&1]++;
        }
        std::cin>>m;
        long long Ans=0;
        for(int i=1;i<=m;++i) {
            std::cin>>b[i];
            Ans+=cnt[b[i]&1];
        }
        std::cout<<Ans<<'\n';
    }
	return 0;
}

