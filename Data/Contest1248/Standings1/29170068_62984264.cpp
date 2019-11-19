#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+200;
ll a[maxn];
bool cmp(int c,int d)
{
	return c<d;
}
int main(){
	int n;scanf("%d",&n);
	ll a1=0,a2=0,m=n/2;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)a1+=a[i];
	for(int i=1;i<=m;i++)a2+=a[n-i+1];
	if(n%2) a2+=a[n/2+1];
	ll ans=1ll*a1*a1+a2*a2;
	printf("%lld\n",ans);
}