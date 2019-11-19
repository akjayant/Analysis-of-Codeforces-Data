#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[501],ans1,ans2,ans=-1;
int main()
{
	ios::sync_with_stdio(false);
	char v;
	int u,mn,mm;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		if(v=='(')
			a[i]=1;
		else
			a[i]=-1;
	}
	u=0,mn=0;
	for(int k=1;k<=n;k++)
		u+=a[k],mn=min(mn,u);
	u=0,mm=0;
	for(int k=1;k<=n;k++)
	{
		u+=a[k];
		if(u==mn)
			mm++;
	}
	if(mm>ans)
		ans=mm,ans1=1,ans2=1;
	if(u)
	{
		cout<<0<<endl<<"1 1"<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			u=0,mn=0;
			swap(a[i],a[j]);
			for(int k=1;k<=n;k++)
				u+=a[k],mn=min(mn,u);
			u=0,mm=0;
			for(int k=1;k<=n;k++)
			{
				u+=a[k];
				if(u==mn)
					mm++;
			}
			if(mm>ans)
				ans=mm,ans1=i,ans2=j;
			swap(a[i],a[j]);
		}
	cout<<ans<<endl<<ans1<<" "<<ans2<<endl;
	return 0;
}