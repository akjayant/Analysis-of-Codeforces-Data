#include<bits/stdc++.h>
#define INF 0x7fffffff
#define pi acos(-1,0)
#define e 2.718281828459
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll n,a[100005];
int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll m=n/2;
	ll x=0,y=0;
	for(int i=1;i<=m;i++){
		x+=a[i];
	}
	for(int i=m+1;i<=n;i++){
		y+=a[i];
	}
	ll ans=x*x+y*y;
	printf("%lld\n",ans);
    return 0;
}