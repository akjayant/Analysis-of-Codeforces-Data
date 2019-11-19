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
#define ll long long
void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    vector<ll>p;
    for(ll i=2;i*i<=n;++i){
        if(n%i==0){
            p.push_back(i);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)p.push_back(n);
    if(p.size()>1)cout<<"1"<<endl;
    else cout<<p[0]<<endl;
}