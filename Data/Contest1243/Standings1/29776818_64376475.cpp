#pragma GCC optimize("-O3")
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve();
signed main(){
#ifdef Sprinkle
   clock_t clock_start=clock();assert(freopen("test.txt","r",stdin));
#else
   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#endif
   solve();
#ifdef Sprinkle
   cerr<<"Running Time: "<<((clock()-clock_start) *1.0 / CLOCKS_PER_SEC)<<"s\n";
#endif
}
#ifdef Sprinkle
void err(){cerr<<"\n";}template<typename T,typename...U>void err(const T&hd,const U&...tl){cerr<<hd<<(sizeof...(tl)?", ":"");err(tl...);}
#define debug(x...) cerr<<""#x" = ";err(x)
#else
#define debug(...) 0
#endif
int a[1005];
void solve(){
    int T=1;cin>>T;
    for(int Case=1;Case<=T;++Case){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        sort(a+1,a+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n;++i){
            if(a[i]>=i){
                ans=max(ans,min(a[i],i));
            }
        }
        cout<<ans<<endl;
    }
}