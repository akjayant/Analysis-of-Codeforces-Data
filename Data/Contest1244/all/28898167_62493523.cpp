#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
const int N=1e5+5;
int a[N];
int n;ll K;

int main()
{
	scanf("%d%lld",&n,&K);
	FOR(i,1,n)scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	ll ans=a[n]-a[1];
	FOR(i,1,n/2)
	{
		ll t;
		int j=n-i+1;

		t=std::min(1ll*a[i+1]-a[i],K/i);
		a[i]+=t;
		K-=i*t;
		ans=a[j]-a[i];

		if(i==n/2&&n%2==0)continue;

		t=std::min(1ll*a[j]-a[j-1],K/i);
		a[j]-=t;
		K-=i*t;
		ans=a[j]-a[i];

		if(a[i]!=a[i+1]||a[j]!=a[j-1])break;
	}
	printf("%lld\n",ans);
	return 0;
}
