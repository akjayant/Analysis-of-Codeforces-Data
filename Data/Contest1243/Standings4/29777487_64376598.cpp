#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define M 1000000007
using namespace std;
const int inf=4e18;
int dp[200000];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int k;cin>>k;
	while(k--)
	{
		int n;cin>>n;
		int a[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		int o=0,mi=inf;
		sort(a,a+n,greater<int> ());
		for(i=0;i<n;i++)
		{
			mi=min(mi,a[i]);
			if(i+1<=mi)
				o=i+1;
		}
		cout<<o<<'\n';
	}
}
