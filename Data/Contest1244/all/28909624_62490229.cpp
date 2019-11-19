#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define lowbit(x) ((x)&(-x))
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define Endl '\n'
#define caze(T) for(cin>>T;T;T--)
#define i16 __int128
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=1<<17;
ll s[N],a[N],b[N];
int n,cc;ll k;
ll ask(int l,int r)
{
	ll ans=0;
	int pos=upper_bound(a+1,a+2+n,l)-a-1;
	ans+=1LL*pos*l-s[pos];
	pos=lower_bound(a+1,a+2+n,r)-a-1;
	ans+=s[n]-s[pos]-1LL*(n-pos)*r;
	return ans;
}
ll chk(int x)
{
	ll ans=1LL<<61;
	for(int i=1;i<=cc;++i)
	{
		ans=min(ans,ask(b[i],b[i]+x));
		ans=min(ans,ask(b[i]-x,b[i]));
	}
	return ans;
}
int main()
{
	while(~scanf("%d%lld",&n,&k))
	{
		a[n+1]=2000000001;
		for(int i=1;i<=n;++i)
			scanf("%lld",a+i),b[i]=a[i];
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		cc=unique(b+1,b+1+n)-b-1;
		for(int i=1;i<=n;++i)
			s[i]=s[i-1]+a[i];
		function<ll(int)>go=[&](int x)
		{
			ll ans=0;
			int pos=upper_bound(a+1,a+2+n,x)-a-1;
			ans+=1LL*pos*x-s[pos];
			pos=lower_bound(a+1,a+2+n,x)-a-1;
			ans+=s[n]-s[pos]-1LL*(n-pos)*x;
			return ans;
		};
		int tp=s[n]/n;
		int ans=2000000001;
		for(int i=tp-1;i<=tp+1;++i)
			if(go(i)<=k)
				ans=0;
		if(!ans)
		{
			printf("%d\n",ans);
			continue;
		}
		int L=0,R=1000000000,mid;
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(chk(mid)<=k)
				ans=mid,R=mid-1;
			else L=mid+1;
		}
		printf("%d\n",ans);
	}
}