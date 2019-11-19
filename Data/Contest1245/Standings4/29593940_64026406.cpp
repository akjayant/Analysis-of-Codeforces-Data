#include<bits/stdc++.h>
using namespace std;
long long dis(auto x,auto y)
{
	return abs(x.first-y.first)+abs(x.second-y.second);
}
vector<long long>father,mi,level;
long long root(long long x)
{
	if(x==father[x])return x;
	return father[x]=root(father[x]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,i,j;
	cin>>n;
	vector<pair<long long,long long>>p(n),anse;
	for(auto &x:p)
		cin>>x.first>>x.second;
	vector<int>c(n),k(n),ansv;
	for(auto &x:c)
		cin>>x;
	for(auto &x:k)
		cin>>x;
	vector<bool>el(n);
	vector<pair<long long,pair<long long,long long>>>v(n*(n-1)/2);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			v.push_back({(k[i]+k[j])*dis(p[i],p[j]),{i,j}});
	sort(v.begin(),v.end());
	father=mi=level=vector<long long>(n,0);
	for(i=0;i<n;i++)
		mi[i]=father[i]=i;
	long long ans=0;
	for(i=0;i<(int)v.size();i++)
	{
		long long x=v[i].second.first;
		long long y=v[i].second.second;
		long long d=v[i].first;
		long long f1=root(x);
		long long f2=root(y);
		if(f1==f2)continue;
		if(max(c[mi[f1]],c[mi[f2]])<d)continue;
		ans+=d;
		if(level[f2]>level[f1])swap(f1,f2);
		if(level[f1]==level[f2])level[f1]++;
		father[f2]=f1;
		if(c[mi[f2]]<c[mi[f1]])mi[f1]=mi[f2];
		anse.push_back({x+1,y+1});
	}
	for(i=0;i<n;i++)
		if(i==father[i])
		{
			ansv.push_back(mi[i]+1);
			ans+=c[mi[i]];
		}
	cout<<ans<<'\n'<<ansv.size()<<"\n";
	for(auto x:ansv)
		cout<<x<<" ";
	cout<<'\n'<<anse.size()<<'\n';
	for(auto x:anse)
		cout<<x.first<<" "<<x.second<<'\n';
}
