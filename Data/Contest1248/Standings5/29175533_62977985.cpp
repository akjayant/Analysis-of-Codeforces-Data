#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define mx 1005
#define mx2 20
#define inf 1e9
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[2] = {0};
		fl(i,0,n)
		{
			int x;
			cin>>x;
			arr[x%2]++;
		}
		int m;
		cin>>m;
		ll ans = 0;
		fl(i,0,m)
		{
			int x;
			cin>>x;
			if(x&1)
			{
				ans += arr[1];
			}
			else
			{
				ans += arr[0];
			}
		}
		cout<<ans<<endl;
	}
}