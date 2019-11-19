#include<bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define int long long int
#define S second
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
const int MOD = 998244353;
//#include <ext/pb_ds/assoc_container.hpp> // Common file 
//#include <ext/pb_ds/tree_policy.hpp>  
//using namespace __gnu_pbds; 
//stringstream ss; string temp; ss<<str(original string) ss>>temp;
int deg[100005];
const int maxn = 100005;
int c1[maxn];
int c2[maxn];
int c3[maxn];
vector<int>g[maxn];
vector<int>ver;

void dfs(int u,int par)
{
	ver.PB(u);
	for(auto x : g[u])
	{
		if(x!=par)
		{
			dfs(x,u);
		}
	}
}

int32_t main()
{	
	boost
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
  	int n; cin>>n;
  	
  	for(int i=1;i<=n;i++)
  	{
  		cin>>c1[i];
  	}
  	//int c2[n+1];
  	for(int i=1;i<=n;i++)
  	{
  		cin>>c2[i];
  	}
  	//int c3[n+1];
  	for(int i=1;i<=n;i++)
  	{
  		cin>>c3[i];
  	}
  	int flg=0;
  	for(int i=1;i<n;i++)
  	{
  		int x,y; cin>>x>>y;
  		g[x].PB(y);
  		g[y].PB(x);
  		deg[x]++;
  		deg[y]++;
  		if(deg[x]>2 || deg[y]>2)
  		{
  			flg=1;
  		}
  	}
  	if(flg==1)
  	{
  		cout<<"-1"<<endl;
  		return 0;
  	}
  	else
  	{
  		int d1 = 1;
  		for(int i=1;i<=n;i++)
  		{
  			if(deg[i]==1)
  			{
  				d1 = i;
  				break;
  			}
  		}
  		dfs(d1,0);
  		int ans = 1e18;
  		map<int,int>mp;
  		int flag = 1;
  		int cost = 0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c1[ver[i]];
  			else if(i%3==1)
  				cost+=c2[ver[i]];
  			else
  				cost+=c3[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=1;
  		}
  		cost=0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c1[ver[i]];
  			else if(i%3==1)
  				cost+=c3[ver[i]];
  			else
  				cost+=c2[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=2;
  		}
  		cost=0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c2[ver[i]];
  			else if(i%3==1)
  				cost+=c1[ver[i]];
  			else
  				cost+=c3[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=3;
  		}
  		cost=0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c2[ver[i]];
  			else if(i%3==1)
  				cost+=c3[ver[i]];
  			else
  				cost+=c1[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=4;
  		}
  		cost=0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c3[ver[i]];
  			else if(i%3==1)
  				cost+=c1[ver[i]];
  			else
  				cost+=c2[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=5;
  		}
  		cost=0;
  		for(int i=0;i<n;i++)
  		{
  			if(i%3==0)
  				cost+=c3[ver[i]];
  			else if(i%3==1)
  				cost+=c2[ver[i]];
  			else
  				cost+=c1[ver[i]];
  		}
  		if(ans > cost)
  		{
  			ans = cost;
  			flag=6;
  		}
  		cost=0;
  		cout<<ans<<endl;

  		if(flag==1)
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 1;
	  			else if(i%3==1)
	  				mp[ver[i]] = 2;
	  			else
	  				mp[ver[i]]=3;
	  		}
  		}
  		else if(flag==2)
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 1;
	  			else if(i%3==1)
	  				mp[ver[i]] = 3;
	  			else
	  				mp[ver[i]]=2;
	  		}
  		}
  		else if(flag==3)
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 2;
	  			else if(i%3==1)
	  				mp[ver[i]] = 1;
	  			else
	  				mp[ver[i]]=3;
	  		}
  		}
  		else if(flag==4)
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 2;
	  			else if(i%3==1)
	  				mp[ver[i]] = 3;
	  			else
	  				mp[ver[i]]=1;
	  		}
  		}
  		else if(flag==5)
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 3;
	  			else if(i%3==1)
	  				mp[ver[i]] = 1;
	  			else
	  				mp[ver[i]]=2;
	  		}
  		}
  		else
  		{
  			for(int i=0;i<n;i++)
	  		{
	  			if(i%3==0)
	  				mp[ver[i]] = 3;
	  			else if(i%3==1)
	  				mp[ver[i]] = 2;
	  			else
	  				mp[ver[i]]=1;
	  		}
  		}

  		for(int i=1;i<=n;i++)
  		{
  			cout<<mp[i]<<" ";
  		}
  		cout<<endl;
  	}
	return 0;
} 
