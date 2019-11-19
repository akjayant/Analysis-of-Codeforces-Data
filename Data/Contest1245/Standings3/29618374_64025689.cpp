#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int N=2018,M=N*N+N,mod=1e9+7;
struct P{
	int x,y;
}p[N];
struct E{
	int u,v;
	LL w;
	bool operator<(const E &t)const{
		return t.w<w;
	}
}e[M];
int n,ec,f[N];
LL k[N],ans;
priority_queue<E> q;
LL myabs(LL x){
	if(x<0)
		return -x;
	return x;
}
int F(int x){
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
vector<P> out;
vector<int> ok;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i].x>>p[i].y;
	for(int i=1;i<=n;++i){
		int c;
		cin>>c;
		q.push((E){n+1,i,c});
	}
	for(int i=1;i<=n;++i)
		cin>>k[i];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			q.push((E){i,j,(k[i]+k[j])*(myabs(p[i].x-p[j].x)+myabs(p[i].y-p[j].y))});
	int cnt=n+1;
	for(int i=1;i<=n+1;++i)
		f[i]=i;
	while(cnt>1){
		LL w=q.top().w;
		int u=q.top().u,v=q.top().v;
		q.pop();
		int uu=F(u),vv=F(v);
		if(uu==vv)
			continue;
		--cnt;
		f[uu]=vv;
		ans+=w;
		if(u==n+1)
			ok.push_back(v);
		else
			out.push_back((P){u,v});
	}
	cout<<ans<<endl;
	cout<<ok.size()<<endl;
	for(int i=0;i<ok.size();++i)
		cout<<ok[i]<<" ";
	cout<<endl;
	cout<<out.size()<<endl;
	for(int i=0;i<out.size();++i)
		cout<<out[i].x<<" "<<out[i].y<<endl;
	return 0;
}
