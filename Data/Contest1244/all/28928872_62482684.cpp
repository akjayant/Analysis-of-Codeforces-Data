#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
LL n,c[5][N],in[N],id[N];
LL fi[N],ec,e[N],nx[N];
LL sum[5][5];
vector<int> vec;
void adde(int u,int v){
	e[++ec]=v;
	nx[ec]=fi[u];
	fi[u]=ec;
}
void dfs(int u,int fa){
	vec.push_back(u);
	for(int i=fi[u];i;i=nx[i]){
		int v=e[i];
		if(v==fa)
			continue;
		dfs(v,u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>c[1][i];
	for(int i=1;i<=n;++i)
		cin>>c[2][i];
	for(int i=1;i<=n;++i)
		cin>>c[3][i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		++in[u];
		++in[v];
		adde(u,v);
		adde(v,u);
	}
	int a=0,b=0;
	for(int i=1;i<=n;++i){
		if(in[i]==1)
			if(a)
				b=i;
			else
				a=i;
		if(in[i]>=3){
			cout<<-1<<endl;
			return 0;
		}
	}
	vec.push_back(0);
	dfs(a,0);
	for(int t=1;t<=3;++t)
		for(int i=1;i<=n;++i)
			sum[t][i%3]+=c[t][vec[i]];
	LL ans1=sum[1][0]+sum[2][1]+sum[3][2];
	LL ans2=sum[1][0]+sum[3][1]+sum[2][2];
	LL ans3=sum[2][0]+sum[1][1]+sum[3][2];
	LL ans4=sum[2][0]+sum[3][1]+sum[1][2];
	LL ans5=sum[3][0]+sum[1][1]+sum[2][2];
	LL ans6=sum[3][0]+sum[2][1]+sum[1][2];
	LL ans=min(ans1,ans2);
	ans=min(ans,ans3);
	ans=min(ans,ans4);
	ans=min(ans,ans5);
	ans=min(ans,ans6);
	cout<<ans<<endl;
//	cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<" "<<ans6<<endl;
//	cout<<vec[1]<<" "<<vec[2]<<" "<<vec[3]<<endl;
	if(ans==ans1)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=1;
			else if(i%3==1)
				id[vec[i]]=2;
			else if(i%3==2)
				id[vec[i]]=3;
	if(ans==ans2)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=1;
			else if(i%3==1)
				id[vec[i]]=3;
			else if(i%3==2)
				id[vec[i]]=2;
	if(ans==ans3)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=2;
			else if(i%3==1)
				id[vec[i]]=1;
			else if(i%3==2)
				id[vec[i]]=3;
	if(ans==ans4)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=2;
			else if(i%3==1)
				id[vec[i]]=3;
			else if(i%3==2)
				id[vec[i]]=1;
	if(ans==ans5)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=3;
			else if(i%3==1)
				id[vec[i]]=1;
			else if(i%3==2)
				id[vec[i]]=2;
	if(ans==ans6)
		for(int i=1;i<=n;++i)
			if(i%3==0)
				id[vec[i]]=3;
			else if(i%3==1)
				id[vec[i]]=2;
			else if(i%3==2)
				id[vec[i]]=1;
	for(int i=1;i<=n;++i)
		cout<<id[i]<<" ";
	return 0;
}
