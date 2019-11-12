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
        vector<pair<int,int>>p;
        for(int i=0;i<n;++i){
            if(s[i]!=t[i]){
                for(int j=i+1;j<n;++j){
                    if(s[i]==s[j]){
                        swap(t[i],s[j]);
                        p.push_back(make_pair(j,i));
                        break;
                    }
                    if(s[i]==t[j]){
                        swap(s[i+1],t[j]);
                        swap(s[i+1],t[i]);
                        p.push_back(make_pair(i+1,j));
                        p.push_back(make_pair(i+1,i));
                        break;
                    }
                }

            }
        }
        if(s==t){
            cout<<"Yes"<<endl<<p.size()<<endl;
            for(auto &x:p){
                cout<<x.first+1<<" "<<x.second+1<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }
}