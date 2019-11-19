#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int x,y;
	long long dis;
} A[4100000];
int n,belong[2020],ans1[2020],tot1;
long long a[2020],b[2020],x[2020],y[2020];
int tot2,ans21[2020],ans22[2020];
bool mycmp(node m,node n)
{
	if(m.dis>n.dis) return false;
	return true;
}
int find(int x)
{
    int fa=x;
    if (belong[x]!=x) fa=find(belong[x]);
    belong[x]=fa;
    return fa;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d%I64d",&x[i],&y[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
	int k=0;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			k++;
			A[k].x=i; A[k].y=j;
			A[k].dis=(b[i]+b[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	for (int i=1;i<=n;i++)
	{
		k++;
		A[k].x=i; A[k].y=n+1;
		A[k].dis=a[i];
	}
	sort(A+1,A+k+1,mycmp);
	for (int i=1;i<=n+1;i++) belong[i]=i;
	int cnt=n; long long ans=0;
	for (int i=1;i<=k;i++)
	{
		int rx=find(A[i].x); int ry=find(A[i].y);
		if (rx!=ry)
		{
			cnt--;
			ans+=A[i].dis;
			belong[rx]=ry;
			if (A[i].y==n+1)
			{
				tot1++;
				ans1[tot1]=A[i].x;
			}
			else
			{
				tot2++;
				ans21[tot2]=A[i].x;
				ans22[tot2]=A[i].y;
			}
		}
		if (!cnt) break;
	}
	printf("%I64d\n",ans);
	printf("%d\n",tot1);
	for (int i=1;i<=tot1;i++) printf("%d ",ans1[i]);
	printf("\n");
	printf("%d\n",tot2);
	for (int i=1;i<=tot2;i++) printf("%d %d\n",ans21[i],ans22[i]);
	//for (int i=1;i<=k;i++) printf("%d ",A[i].dis);
}