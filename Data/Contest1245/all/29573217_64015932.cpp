#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define abs(x) (x>0?x:-(x))
using namespace std;

struct type{
	int x,y;
	long long s;
} a[4004001];
int x[2002];
int y[2002];
int c[2002];
int K[2002];
int fa[2002];
int ans[2002][2];
bool bz[2002];
int n,i,j,k,l,len,tot,sum;
long long Ans;

bool cmp(type a,type b)
{
	return a.s<b.s;
}

int gf(int t)
{
	if (fa[t]==t)
	return t;
	fa[t]=gf(fa[t]);
	return fa[t];
}

int main()
{
//	freopen("d.in","r",stdin);
	
	scanf("%d",&n);
	fo(i,1,n)
	scanf("%d%d",&x[i],&y[i]);
	fo(i,1,n)
	scanf("%d",&c[i]);
	fo(i,1,n)
	scanf("%d",&K[i]);
	
	fo(i,1,n)
	{
		fo(j,i+1,n)
		{
			++len;
			a[len].x=i;
			a[len].y=j;
			a[len].s=((long long)K[i]+K[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
		
		++len;
		a[len].x=i;
		a[len].y=n+1;
		a[len].s=c[i];
	}
	
	fo(i,1,n+1) fa[i]=i;
	
	sort(a+1,a+len+1,cmp);
	
	fo(i,1,len)
	if (gf(a[i].x)!=gf(a[i].y))
	{
		fa[fa[a[i].x]]=fa[a[i].y];
		
		Ans+=a[i].s;
		
		if (a[i].y==n+1)
		bz[a[i].x]=1,++sum;
		else
		{
			++tot;
			ans[tot][0]=a[i].x;
			ans[tot][1]=a[i].y;
		}
	}
	
	printf("%I64d\n",Ans);
	printf("%d\n",sum);
	fo(i,1,n)
	if (bz[i])
	printf("%d ",i);
	printf("\n");
	printf("%d\n",tot);
	fo(i,1,tot)
	printf("%d %d\n",ans[i][0],ans[i][1]);
}