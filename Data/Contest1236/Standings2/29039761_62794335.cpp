#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

ll n;
vector<ll> g[500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				g[j].push_back((i-1)*n+j);
		}
		else
		{
			for(int j=1;j<=n;j++)
				g[n+1-j].push_back((i-1)*n+j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<g[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}