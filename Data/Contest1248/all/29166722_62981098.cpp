#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("E:\\Gokul\\atomic_gpp", "r", stdin);
	freopen("E:\\Gokul\\atomic_gpp", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		int n,m,qo=0,qe=0,po=0,pe=0;
		cin>>n;
		vector<long long>p(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			if(p[i]%2)
				po++;
			else
				pe++;
		}
		cin>>m;
		vector<long long>q(m+1);
		for(int i=1;i<=m;i++)
		{
			cin>>q[i];
			if(q[i]%2)
				qo++;
			else
				qe++;
		}
		long long ans=qo*1ll*po+qe*1ll*pe;
		cout<<ans<<"\n";
	}
	return 0;
}