/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
using namespace std;
 
#define N  100005

ll int nxt(ll int idx,ll int n)
{
	if(idx==n) return 1;
	else return idx+1;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	// cin>>TESTS;
	while(TESTS--)
	{
		ll int n;
		cin>>n;
		vi v[n+1];
		ll int cnt=1;
		for(ll int i=1;i<=n;i++)
		{
			if(i%2==1)
			for(ll int j=1;j<=n;j++)
			{
				// cout<<st<<" ";
				v[j].pb(cnt++);
			}	
			else
			for(ll int j=n;j>=1;j--)
			{
				// cout<<st<<" ";
				v[j].pb(cnt++);
			}	
			// cout<<endl;
		}
		for(ll int i=1;i<=n;i++)
		{
			for(ll int j=0;j<n;j++)
			{
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}