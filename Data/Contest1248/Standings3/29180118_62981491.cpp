#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int t;
int n,m; 
int a[100005];
int b[100005];
ll ans=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		ll ou1=0;
		ll ou2=0;
		ll ji1=0;
		ll ji2=0;
		 
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (abs(a[i])%2==0)
			{
				ou1++;
			}
			else
			{
				ji1++;
			}
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			if (abs(b[i])%2==0)
			{
				ou2++;
			}
			else
			{
				ji2++;
			}
		}
		ans=ou1*ou2+ji1*ji2;
		cout<<ans<<endl;
		
		
	}
}
