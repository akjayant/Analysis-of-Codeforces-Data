
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
typedef long long ll;
//typedef __int128 LL;
const double eps=10e-8;
const double pi=acos(-1.0);
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,ll> pII;
typedef pair<int,int> pii;
typedef pair<int,ll> piI;

ll a[MAXN];
int main()
{

    ll n,m;

    scanf("%lld%lld",&n,&m);
    int ma=max(n,m);
    a[1]=2,a[2]=4;
    for(int i=3;i<=ma;i++)a[i]=(a[i-1]+a[i-2])%mod;
    printf("%lld\n",(a[n]+a[m]-2)%mod);


    return 0;
}