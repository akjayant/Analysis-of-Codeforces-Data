#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define g 9.8
#define m(a,b) make_pair(a,b)
const ll mod = 1e9+7;
ull base = 131;
const int w = 1e5+5;
int n,m,k;
ll a[w];
ll sum[w];
int main()
{
	int i,j,t;
    a[2]=2,a[3]=2;
    sum[2]=2,sum[3]=4;
    for(i=4;i<w;i++) a[i]=((a[i-1]+a[i-2])%mod+mod)%mod,sum[i]=((sum[i-1]+a[i])%mod+mod)%mod;
    scanf("%d %d",&n,&m);
    ll ans=(2+sum[n]+sum[m])%mod;
    printf("%lld\n",ans);
    return 0;
}