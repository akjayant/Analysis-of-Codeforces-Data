#include<bits/stdc++.h>
using namespace std;
int n,m,p[111111],l[111111],r[111111],x,g,lb,rb;
long long ans;
map<int,vector<int> > mp1,mp2;
vector<int> v;
int main()
{
	scanf("%d%d",&n,&m);
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=m;i++) scanf("%d",&p[i]);
	for (int i=1;i<=m;i++) 
	{
		mp1[p[i]-i].push_back(i);
		mp2[p[i]+i].push_back(i);
	}
	l[m]=p[m];r[m]=p[m];
	for (int i=m-1;i>=1;i--)
	{
		v=mp1[p[i]-1-i];
		g=lower_bound(v.begin(),v.end(),i+1)-v.begin();
		if (g==(int)v.size()) r[i]=min(n,p[i]+m-i);
		else r[i]=r[v[g]];
	}
	for (int i=m-1;i>=1;i--)
	{
		v=mp2[p[i]+1+i];
		g=lower_bound(v.begin(),v.end(),i+1)-v.begin();
		if (g==(int)v.size()) l[i]=max(1,p[i]-m+i);
		else l[i]=l[v[g]];
	}
	for (int i=1;i<=n;i++)
	{
		v=mp1[i];
		if (v.empty()) rb=min(n,i+m+1);
		else rb=r[v[0]];
		v=mp2[i];
		if (v.empty()) lb=max(1,i-m-1);
		else lb=l[v[0]];
		if (lb<=rb) ans+=(rb-lb+1);
	}
	printf("%lld\n",ans);
	return 0;
}