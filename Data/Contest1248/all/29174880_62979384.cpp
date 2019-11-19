#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,js1=0,os1=0,js2=0,os2=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x%2==0)
				os1++;
			else
				js1++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			if(x%2==0)
				os2++;
			else
				js2++;
		}
		ans=1ll*os2*os1+1ll*js1*js2;
		cout<<ans<<endl;
	}
	return 0;
}