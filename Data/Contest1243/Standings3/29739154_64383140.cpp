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
        ll n,d;
        pair<ll,char> dd;
        string s,t;
        map<pair<ll,char>,ll> m;
        m.clear();
        cin>>n>>s>>t;
        if(s==t){
            cout<<"NO"<<'\n';
            C;
        }
        for(int i=0;i<n;i++){
            d=(int)(s[i]-t[i]);
            if(d!=0){
                m[{d,s[i]}]++;
                dd={d,s[i]};
            }
        }
        if(m.size()>1){
            cout<<"NO"<<'\n';
            C;
        }
        if(m[dd]!=2){
            cout<<"NO"<<'\n';
            C;
        }
        cout<<"YES"<<'\n';
    }


    return 0;
}
