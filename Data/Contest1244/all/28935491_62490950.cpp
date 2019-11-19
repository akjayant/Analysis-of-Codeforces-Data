#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007 
#define mx 100005
#define mx2 19
#define inf 1e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);          return x; 
vector<int> v[mx];
ll arr[mx][3];
vector<int> g;
void dfs(int x,int p)
{
	g.pb(x);
	if(v[x].size() > 2)
	{
		cout<<-1;
		exit(0);
	}
	fl(i,0,v[x].size())
	{
		if(v[x][i] != p)
		{
			dfs(v[x][i],x);
		}
	}
}
main()
{
	int n;
	cin>>n;
	fl(i,0,3)
	{
		fl(j,0,n)
		{
			cin>>arr[j][i];
		}
	}
	fl(i,1,n)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	fl(i,1,n+1)
	{
		if(v[i].size() == 1)
		{
			dfs(i,0);
			break;
		}
	}
	ll ans = inf;
	ll cost = 0;
	int brr[] = {0,1,2};
	int id = 0; 
	fl(j,0,6)
	{
		fl(i,0,n)
		{
			int x = g[i] - 1;
			cost += arr[x][brr[i%3]];
		}
		if(cost < ans)
		{
			ans = cost;
			id = j;
		}	//	cout<<cost<<endl;
		next_permutation(brr,brr+3);

		cost = 0;
	}

	cout<<ans<<endl;
	sort(brr,brr+3);
	int ansr[n];
	fl(j,0,6)
	{
		if( id == j)
		{
			fl(i,0,n)
			{
				ansr[g[i]-1] = brr[i%3] + 1;
			}
			fl(i,0,n)
			{
				cout<<ansr[i]<<" ";
			}
			return 0;
		}
		next_permutation(brr,brr+3);
	}

	cout<<ans;
	


}