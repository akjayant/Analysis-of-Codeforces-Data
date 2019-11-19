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
const int w = 2e5+5;
int n,m,k;
ll a[w];
int cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
    sort(a+1,a+n+1,cmp);
    ll ans1=0;
    for(i=1;i<=(n+1)/2;i++) ans1+=a[i];
    ll ans2=0;
    for(i=(n+1)/2+1;i<=n;i++) 
		ans2+=a[i];
    ll ans=ans1*ans1+ans2*ans2;
    printf("%lld\n",ans);
    return 0;
}