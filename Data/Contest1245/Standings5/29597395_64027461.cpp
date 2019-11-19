#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#define int long long
using namespace std;
int f[100001];
int x[100005],y[100005];
int cost[100005],k[100005];
int num1,num2;
int pot[100005];
int frm[100005],to[100005];
int getf(int v)
{
    if(v==f[v])return f[v];
    f[v]=getf(f[v]);
    return f[v];
}
int merge(int a,int b)
{
    int t1,t2;
    t1=getf(a);
    t2=getf(b);
    if(t1!=t2)
    {
        f[t2]=t1;
        return 1;
    }
    return 0;
}
struct node
{
    int x,y,z;
}a[5000005];
bool cmp(node a,node b)
{
    return a.z<b.z;
}
int num;
signed main()
{
    int n;
    scanf("%lld",&n);
	for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&cost[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&k[i]);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
    	tot++;
    	a[tot].x=0;
    	a[tot].y=i;
    	a[tot].z=cost[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			tot++;
			a[tot].x=i;
			a[tot].y=j;
			a[tot].z=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	}
	sort(a+1,a+tot+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(merge(a[i].x,a[i].y))
		{
			ans+=a[i].z;
			cnt++;
			if(a[i].x==0)
			{
				num1++;
				pot[num1]=a[i].y;
			}
			else
			{
				num2++;
				frm[num2]=a[i].x;
				to[num2]=a[i].y; 
			}
		}
		if(cnt==n)
		    break;
	}
	cout<<ans<<endl;
	cout<<num1<<endl;
	for(int i=1;i<=num1;i++)
	    cout<<pot[i]<<" ";
	cout<<endl;
	cout<<num2<<endl;
	for(int i=1;i<=num2;i++)
        cout<<frm[i]<<" "<<to[i]<<endl;
}