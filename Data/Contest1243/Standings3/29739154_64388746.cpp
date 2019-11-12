#include <bits/stdc++.h>
#define ll long long
#define R return
#define B break
#define C continue
#define sf scanf
#define pf printf
#define pb push_back
#define F first
#define S second

using namespace std;

ll Mod=1e9+7;
int poww(int a,int b,int mod){
    int res=1;if(b<0)b=(b%(mod-1)+mod-1)%(mod-1);
    for(;b;b>>=1,a=1ll*a*a%mod)
      if(b&1)res=1ll*res*a%mod;
    return res;
}

void Max(ll& x,ll y){
x=max(x,y);
}
void Min(ll& x,ll y){
x=min(x,y);
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t,Ans=0;
    cin>>t;
    while(t--){
        ll n,Cnt[30],W=0;
        vector<pair<ll,ll>> v;
        string s,t;
        cin>>n>>s>>t;
        for(int i=0;i<28;i++)Cnt[i]=0;
        for(int i=0;i<n;i++){
            Cnt[s[i]-'a']++;
            Cnt[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(Cnt[i]&1){W=1;B;}
        }
        if(W){
            cout<<"NO"<<'\n';
            C;
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        swap(t[i],s[j]);
                        v.pb({j+1,i+1});
                        B;
                    }
                    if(t[j]==s[i]){
                        swap(t[j],s[j]);
                        swap(t[i],s[j]);
                        v.pb({j+1,j+1});
                        v.pb({j+1,i+1});
                        B;
                    }
                }
            }
        }
        cout<<"YES"<<'\n';
        cout<<v.size()<<'\n';
        for(auto pp:v){
            cout<<pp.F<<' '<<pp.S<<'\n';
        }
    }


    return 0;
}
