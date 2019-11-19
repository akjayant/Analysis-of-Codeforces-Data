#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,x[2010],y[2010],c[2010],k[2010],p[2010],val[2010],idx[2010];
vector<pair<int,pair<int,int> > > v;
vector<int> res;
vector<pair<int,int> > w;

inline int find_set(int x)
{
	if(p[x]==x) return x;
	return p[x]=find_set(p[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	int sum=0;
	for(int i=1;i<=n;i++){cin>>c[i];sum+=c[i];val[i]=c[i];}
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(i!=j){
			int num=abs(x[i]-x[j])+abs(y[i]-y[j]);
			num*=(k[i]+k[j]);
			v.push_back(make_pair(num,make_pair(i,j)));
		}
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){p[i]=i;idx[i]=i;}
	for(int i=0;i<v.size();i++){
		int dis=v[i].first;
		int xx=v[i].second.first,yy=v[i].second.second;
		int rootx=find_set(xx),rooty=find_set(yy);
		if(rootx==rooty) continue;
		int u=max(val[rootx],val[rooty]);
		if(dis>=u) continue;
		p[rooty]=rootx;
		if(val[rootx]>val[rooty]) idx[rootx]=idx[rooty];
		idx[rooty]=0;
		val[rootx]=min(val[rootx],val[rooty]);
		val[rooty]=0;
		sum-=u;
		sum+=dis;
		w.push_back(make_pair(xx,yy));
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++) if(idx[i]!=0){
		res.push_back(idx[i]);
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;
	cout<<w.size()<<endl;
	for(int i=0;i<w.size();i++) cout<<w[i].first<<" "<<w[i].second<<endl;
	return 0;
}