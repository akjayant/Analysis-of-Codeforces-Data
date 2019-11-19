#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	long long int n,k,temp=0;
	cin>>n>>k;
	long long int a[n],d[n-1];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//a[0]=0;
	sort(a,a+n);
	for (int i = 1; i < n; ++i)
	{
		d[i-1]=a[i]-a[i-1];
	}
	long long int l=1,m=1,t=0,tt=n-2;
	long long int ans=a[n-1]-a[0];
	while(t<=tt && k>0 && ans>0)
	{
		if (l<m)
		{
			k-=d[t]*l;
			ans-=d[t];
			if (k<0)
			{
				ans+=d[t];
				k+=d[t]*l;
				break;
			}
			l++;
			t++;
		}
		else
		{
			k-=d[tt]*m;
			ans-=d[tt];
			if (k<0)
			{
				ans+=d[tt];
				k+=d[tt]*l;
				break;
			}
			m++;
			tt--;
		}
	}
	if (k>0)
	{
		ans=max(temp,ans-k/min(l,m));
	}
	cout<<max(ans,temp)<<endl;
}