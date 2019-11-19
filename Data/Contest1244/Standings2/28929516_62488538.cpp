#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define min(a,b) (a<b?a:b)
using namespace std;

int a[200001][2];
int ls[100001];
int x[100001][3];
int d[100001];
int D[100001];
int Ans[100001];
int n,i,j,k,l,len,st;
long long s,ans;

void New(int x,int y)
{
	++len;
	a[len][0]=y;
	a[len][1]=ls[x];
	ls[x]=len;
}

void dfs(int Fa,int t)
{
	int i;
	
	d[++l]=t;
	
	for (i=ls[t]; i; i=a[i][1])
	if (a[i][0]!=Fa)
	dfs(t,a[i][0]);
}

int main()
{
//	freopen("d.in","r",stdin);
	
	scanf("%d",&n);
	fo(j,0,2)
	{
		fo(i,1,n)
		scanf("%d",&x[i][j]);
	}
	
	fo(i,2,n)
	{
		scanf("%d%d",&j,&k);
		
		New(j,k);
		New(k,j);
		
		++D[j];
		++D[k];
	}
	
	fo(i,1,n)
	if (D[i]>2)
	{
		printf("-1\n");
		return 0;
	}
	else
	if (D[i]==1)
	st=i;
	
	l=0;
	dfs(0,st);
	
	ans=1000000000000000000ll;
	fo(j,0,2)
	{
		fo(k,0,2)
		if (j!=k)
		{
			s=0;
			
			if (j!=0 && k!=0) l=0;
			if (j!=1 && k!=1) l=1;
			if (j!=2 && k!=2) l=2;
			
			fo(i,1,n)
			{
				switch (i%3)
				{
					case 0:{s+=x[d[i]][j]; break;}
					case 1:{s+=x[d[i]][k]; break;}
					case 2:{s+=x[d[i]][l]; break;}
				}
			}
			
			if (s<ans)
			{
				fo(i,1,n)
				{
					switch (i%3)
					{
						case 0:{Ans[d[i]]=j; break;}
						case 1:{Ans[d[i]]=k; break;}
						case 2:{Ans[d[i]]=l; break;}
					}
				}
				ans=s;
			}
		}
	}
	
	printf("%I64d\n",ans);
	fo(i,1,n)
	printf("%d ",Ans[i]+1);
}