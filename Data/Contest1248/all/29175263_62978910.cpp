#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
long long t,n,m,js[2],os[2],ans;
int main()
{
	ios::sync_with_stdio(false);
	int u;
	cin>>t;
	while(t--)
	{
		js[0]=js[1]=os[0]=os[1]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>u;
			if(u&1)
				js[0]++;
			else
				os[0]++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>u;
			if(u&1)
				js[1]++;
			else
				os[1]++;
		}
		ans=js[0]*js[1]+os[0]*os[1];
		cout<<ans<<endl;
	}
	return 0;
}