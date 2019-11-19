#include<bits/stdc++.h>
#define mxn 1000010
#define db double
#define LL long long
#define ldb long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair<int,int> 
#define mp make_pair
#define fr first
#define sc second
using namespace std;
const int mod=1e9+7;
LL n,K,sl,fh,ans,a[mxn],p[mxn],s[mxn];
LL rd()
{
    sl=0;fh=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
    while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
    return sl*fh;
}
bool check(LL d)
{
	LL res=1e18;
	for(int ps,i=1;i<=n;++i)
	{
		ps=upper_bound(a+1,a+n+1,a[i]+d)-a;
		res=min(res,a[i]*(i-1)-p[i-1]+s[ps]-(a[i]+d)*(n-ps+1));
	}
	for(int ps,i=n;i;--i)
	{
		ps=lower_bound(a+1,a+n+1,a[i]-d)-a;
		res=min(res,s[i+1]-a[i]*(n-i)+(a[i]-d)*(ps-1)-p[ps-1]);
	}
	return res<=K;
}
int main()
{
	n=rd();K=rd();
	for(int i=1;i<=n;++i) a[i]=rd();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) p[i]=p[i-1]+a[i];
	for(int i=n;i;--i) s[i]=s[i+1]+a[i];
	LL mid,l=0,r=a[n]-a[1];ans=r;
	for(;l<=r;)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}