#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100006;
vector<int>vec[maxn];
int n;
#define ll long long
ll c[maxn][3];
int a[maxn],an[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<=n;j++)scanf("%lld",&c[j][i]);
	}
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(vec[i].size()>=3)
		{
			printf("-1");return 0;
		}
		if(vec[i].size()==1)a[1]=i;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i-1]==vec[a[i]][0])a[i+1]=vec[a[i]][1];
		else a[i+1]=vec[a[i]][0];
	}
	//for(int i=1;i<=n;i++)printf("%d ",a[i]);puts(""); 
	ll ans=1e18,p,q;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)continue;
			ll w=c[a[1]][i]+c[a[2]][j];
			int tmp[3]={3-i-j,i,j};
			for(int x=3;x<=n;x++)w+=c[a[x]][tmp[x%3]];
			if(ans>w)ans=w,p=i,q=j;
		}
	}
	printf("%lld\n",ans);
	int tmp[3]={4-p-q,p+1,q+1};
	for(int i=1;i<=n;i++)an[a[i]]=tmp[i%3];
	for(int i=1;i<=n;i++)printf("%d ",an[i]);
	return 0;
}
