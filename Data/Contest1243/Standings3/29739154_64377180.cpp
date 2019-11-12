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
        ll n;
        cin>>n;
        ll Cnt[n+7];
        for(int i=n+4;i>=0;i--){
            Cnt[i]=0;
        }
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            Cnt[x]++;
        }
        for(int i=n;i>=1;i--){
            Cnt[i]+=Cnt[i+1];
            if(Cnt[i]>=i){
                Ans=i;
                B;
            }
        }
        cout<<Ans<<'\n';
    }


    return 0;
}
