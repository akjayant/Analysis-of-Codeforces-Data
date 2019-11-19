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

    ll t=1;
    while(t--){
        ll n,Ans;
        cin>>n;
        Ans=n;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                Ans=__gcd(Ans,i);
                Ans=__gcd(Ans,n/i);
            }
        }
        cout<<Ans<<'\n';
    }


    return 0;
}
