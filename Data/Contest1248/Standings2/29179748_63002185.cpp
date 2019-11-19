#include <bits/stdc++.h>

template <class T>
bool Enlarge(T &a,T const &b) {
    return a<b?a=b,1:0;
}

const int XN=5e2+11;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int n;std::cin>>n;
    static char s[XN];
    std::cin>>(s+1);
    int Ans=0;std::pair<int,int> p={1,1};
    int cnt[2]={0};
    for(int i=1;i<=n;++i)
        cnt[s[i]==')']++;
    if(cnt[0]==cnt[1]) {
        for(int l=1;l<=n;++l)
            for(int r=l;r<=n;++r) {
                std::swap(s[l],s[r]);
                static int sum[XN],pre[XN],suf[XN];
                for(int i=1;i<=n;++i)
                    sum[i]=sum[i-1]+(s[i]=='('?1:-1);
                pre[0]=suf[n+1]=1e9;
                for(int i=1;i<=n;++i)
                    pre[i]=std::min(sum[i],pre[i-1]);
                for(int i=n;i>=1;--i)
                    suf[i]=std::min(sum[i],suf[i+1]);
                int cnt=pre[n]>=0;
                for(int i=2;i<=n;++i)
                    cnt+=std::min(suf[i]-sum[i-1],sum[n]-sum[i-1]+pre[i-1])>=0;
                if(Enlarge(Ans,cnt))
                    p={l,r};
                std::swap(s[l],s[r]);
            }
    }
    std::cout<<Ans<<'\n'<<p.first<<' '<<p.second<<'\n';
	return 0;
}

