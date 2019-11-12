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
void solve(){
    int T=1;cin>>T;
    for(int Case=1;Case<=T;++Case){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        if(s==t){
            cout<<"Yes"<<endl;
            continue;
        }
        int inx1=-1,inx2=-1;
        for(int i=0;i<n;++i){
            if(s[i]!=t[i]){
                inx1=i;
                break;
            }
        }
        for(int i=inx1+1;i<n;++i){
            if(s[i]!=t[i]){
                inx2=i;
                break;
            }
        }
        if(inx1==-1||inx2==-1){
            cout<<"No"<<endl;
            continue;
        }
        swap(s[inx1],t[inx2]);
        if(s==t)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}