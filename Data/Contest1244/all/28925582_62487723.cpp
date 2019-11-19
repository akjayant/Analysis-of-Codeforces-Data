#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100005
int c1[M],c2[M],c3[M],sz[M],sk[M],cnt,col[M];
ll sum1[3],sum2[3],sum3[3];
vector<int>d[M];
void dfs(int x,int f){
	sk[++cnt]=x;
	for(int i=0;i<(int)d[x].size();++i){
		int v=d[x][i];
		if(v==f)continue;
		dfs(v,x);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c1[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c2[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c3[i]);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		d[x].push_back(y);
		d[y].push_back(x);
	}int st=0;
	for(int i=1;i<=n;++i){
		if(d[i].size()<=1)st=i;
		else if(d[i].size()>2){
			puts("-1");
			return 0;
		}
	}
	dfs(st,0);
	for(int i=1;i<=n;i+=3)sum1[0]+=c1[sk[i]],sum2[0]+=c2[sk[i]],sum3[0]+=c3[sk[i]];
	for(int i=2;i<=n;i+=3)sum1[1]+=c1[sk[i]],sum2[1]+=c2[sk[i]],sum3[1]+=c3[sk[i]];
	for(int i=3;i<=n;i+=3)sum1[2]+=c1[sk[i]],sum2[2]+=c2[sk[i]],sum3[2]+=c3[sk[i]];
	ll ans=1e18,id1,id2,id3;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				if(i!=j&&i!=k&&j!=k&&sum1[i]+sum2[j]+sum3[k]<ans){
					ans=sum1[i]+sum2[j]+sum3[k];
					id1=i,id2=j,id3=k;
				}
	for(int i=id1+1;i<=n;i+=3)col[sk[i]]=1;
	for(int i=id2+1;i<=n;i+=3)col[sk[i]]=2;
	for(int i=id3+1;i<=n;i+=3)col[sk[i]]=3;
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i)printf("%d ",col[i]);
}