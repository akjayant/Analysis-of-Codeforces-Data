#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int MN=101010;
struct Ed{
	int to,ne;
}e[MN*2];
int cost[MN][4],d[MN],first[MN],id,n;
void adde(int fr,int to)
{
	e[++id].to=to;
	e[id].ne=first[fr];
	first[fr]=id;
	d[fr]++;
}
int ca[MN][7];
long long minn[7];
int cnt=0;
void dfs(int p,int fa,int nc,int qc,long long nowcost,int ges)
{
	for(int i=first[p];i;i=e[i].ne)
	{
		int to=e[i].to;
		if(to==fa)
			continue;
		ca[to][cnt+1]=6-nc-qc;
		dfs(to,p,6-nc-qc,nc,1ll*nowcost+cost[to][6-nc-qc],ges+1);
	}
	if(ges==n)
	{
//		cout<<nowcost<<'*'<<endl;
		minn[++cnt]=nowcost;
		return;
	}
}
void fz(int fr,int to,int fc,int nc)
{
	ca[fr][cnt+1]=fc;
	ca[to][cnt+1]=nc;
	dfs(fr,to,fc,nc,cost[fr][fc]+cost[to][nc],2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>cost[i][1];
	for(int i=1;i<=n;i++)
		cin>>cost[i][2];
	for(int i=1;i<=n;i++)
		cin>>cost[i][3];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adde(u,v);
		adde(v,u);
	}
	int fi=0,se=0;
	for(int i=1;i<=n;i++)
		if(d[i]==1)
			fi=i;
		else if(d[i]>2)
		{
			cout<<-1<<endl;
			return 0;
		}

	se=e[first[fi]].to;
	fz(se,fi,1,2);
	fz(se,fi,1,3);
	fz(se,fi,2,1);
	fz(se,fi,2,3);
	fz(se,fi,3,1);
	fz(se,fi,3,2);
	int minp=1;
	for(int i=2;i<=6;i++)
	{
		if(minn[minp]>minn[i])
			minp=i;
	}
	cout<<minn[minp]<<endl;
	for(int i=1;i<=n;i++)
		cout<<ca[i][minp]<<' ';
	cout<<endl;
	return 0;
}