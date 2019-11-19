#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>
#define PII pair<int,int>
#define test freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2019;
bool vis[maxn];
int n;
PII pos[maxn];
LL c[maxn],k[maxn];
struct nod
{
	int id;
	LL spd;
	nod(const int tid=0,const LL tspd=1e18) {id=tid;spd=tspd;}
}lik[maxn];
int dis(int lhs,int rhs) 
{
	return abs(pos[lhs].first-pos[rhs].first)+abs(pos[lhs].second-pos[rhs].second);
}
int main()
{
	//test
	scanf("%d",&n);
	vector<int>ans1;
	vector<PII>ans2;
	for(int i=1;i<=n;++i) scanf("%d%d",&pos[i].first,&pos[i].second);
	for(int i=1;i<=n;++i) scanf("%I64d",c+i);
	for(int i=1;i<=n;++i) scanf("%I64d",k+i);
	LL ans=0;
	for(int i=1;i<=n;++i)
	{
		int nexp=-1;
		LL spd=1e18;
		for(int j=1;j<=n;++j) 
		{
			if(!vis[j]&&spd>min(lik[j].spd,c[j])) 
			{
				spd=min(lik[j].spd,c[j]);
				nexp=j;
			} 
		}
		if(spd==c[nexp]) ans1.push_back(nexp);
		else ans2.push_back(make_pair(lik[nexp].id,nexp));
		vis[nexp]=1;
		ans+=spd;c[nexp]=1e18;
		for(int j=1;j<=n;++j) 
		{
			if(!vis[j]) 
			{
				LL t=dis(nexp,j)*(k[j]+k[nexp]);
				if(t<lik[j].spd) lik[j]=nod(nexp,t);
			}
		}
	}
	printf("%I64d\n",ans);
	printf("%u\n",ans1.size());
	for(int i=0;i<ans1.size();++i) printf("%d ",ans1[i]);
	printf("\n%u\n",ans2.size());
	for(int i=0;i<ans2.size();++i) printf("%d %d\n",ans2[i].first,ans2[i].second);
	return 0;
}