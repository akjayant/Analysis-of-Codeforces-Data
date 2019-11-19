#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,m,c[2][2]={0};
		cin>>n;
		for(ll i=1,a;i<=n;++i)cin>>a,c[0][a%2]++;
		cin>>m;
		for(ll i=1,a;i<=m;++i)cin>>a,c[1][a%2]++;
		cout<<c[0][0]*c[1][0]+c[0][1]*c[1][1]<<endl;
	}
	return 0;
}