#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
int n;
ll k;
ll a[maxn],b[maxn];
ll presum[maxn],bcksum[maxn];
int precnt[maxn],bckcnt[maxn];
vector<ll> lsh;
bool check(ll val)
{
	ll cst=linf;
	for(int i=0;i<n;i++)
	{
		ll lb=a[i],rb=a[i]+val;
		if(rb>lsh.back())rb=lsh.back();
		ll cur=presum[b[i]];
		int pb=lower_bound(lsh.begin(),lsh.end(),rb)-lsh.begin();
		cur+=bcksum[pb]+bckcnt[pb]*1ll*(lsh[pb]-rb);
		cst=min(cst,cur);
		
		rb=a[i],lb=max(lsh[0],a[i]-val);
		cur=bcksum[b[i]];
		pb=lower_bound(lsh.begin(),lsh.end(),lb)-lsh.begin();
		if(pb!=0)
		{
			pb--;
			cur+=presum[pb];
			cur+=precnt[pb]*1ll*(lb-lsh[pb]);
		}
		cst=min(cst,cur);
	}
//	cout<<val<<" "<<cst<<endl;
	return cst<=k;
}
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		lsh.emplace_back(a[i]);
	}
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	if(lsh.size()==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		b[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin();
		precnt[b[i]]++;
		bckcnt[b[i]]++;
	}
	for(int i=1;i<lsh.size();i++)
	{
		{
			precnt[i]+=precnt[i-1];
			presum[i]=presum[i-1]+precnt[i-1]*1ll*(lsh[i]-lsh[i-1]);
		}
	}
	
	for(int i=lsh.size()-2;i>=0;i--)
	{
		bckcnt[i]+=bckcnt[i+1];
		bcksum[i]=bcksum[i+1]+bckcnt[i+1]*1ll*(lsh[i+1]-lsh[i]);
	}
	
	ll l=-1,r=inf;
	while(l+1<r)
	{
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%I64d\n",r);
	return 0;
}