#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define ll long long
#define sf(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define sfc(a) scanf("%c",&a);
#define pf(a) printf("%d\n",a);
#define pfl(a) printf("%lld\n",a);
#define pb push_back
#define ft first
#define sd second
typedef pair<ll, ll> PII;
#define MAXN 100001

ll dp1[MAXN];
ll dp2[MAXN];
ll ss[MAXN];

int main() {

    ll n1,m1;
    sfl(n1) sfl(m1)

    ll n,m;
    n=min(n1,m1);
    m=max(n1,m1);

    ll i,j,k,l;

    dp1[1]=1;
    dp1[2]=2;
    for(i=3;i<=m;i++)
        dp1[i]=(dp1[i-1]+dp1[i-2])%mod;

    dp2[1]=1;
    dp2[2]=1;
    ss[1]=1;
    ss[2]=2;

    for(i=3;i<=n+1;i++){
        dp2[i]=(dp2[i-1]+dp2[i-2])%mod;
        ss[i]=ss[i-1]+dp2[i];
    }

   // cout<<dp1[m]<<"@";
    cout<<((dp1[m]+ss[n-1])*2)%mod;

    return 0;
}
