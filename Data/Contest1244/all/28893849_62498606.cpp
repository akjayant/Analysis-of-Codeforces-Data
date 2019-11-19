#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e5+9;
LL n,k;
LL a[N];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
bool check(LL mid)
{
	LL l=1,r=n,ans=0;
	while(a[r]-a[l]>mid)
	{
		while(a[l+1]==a[l])	++l;
		while(a[r-1]==a[r])	--r;
		if(l<n-r+1)
		{
			ans+=l*(min(a[r]-mid,a[l+1])-a[l]);
			++l;
		}
		else
		{
			ans+=(n-r+1)*(a[r]-max(a[l]+mid,a[r-1]));
			--r;
		}
	}
	return ans<=k;
}
int main()
{
	read(n);read(k);
	for(LL i=1;i<=n;++i)
		read(a[i]);
	sort(a+1,a+n+1);
	LL l=0,r=a[n]-a[1],ans;
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%I64d",ans);
	return 0;
}