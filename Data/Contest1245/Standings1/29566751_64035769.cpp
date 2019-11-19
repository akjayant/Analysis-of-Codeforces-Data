#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18;
ll l,r,r1;
ll dp[31][4][2];
ll solve(ll i,ll f1,ll f2)
{
	// 1 > l
	// 2 < r
	// 3 both
	if(i==-1)
	{
		return 1;
	}
	if(dp[i][f1][f2]==-1)
	{
		dp[i][f1][f2]=0;
		ll bl=0,br=0,br1=0;
		if(((1<<i)&r)!=0)
		{
			br=1;
		}
		if(((1<<i)&l)!=0)
		{
			bl=1;
		}
		if(((1<<i)&r1)!=0)
		{
			br1=1;
		}
		if(f2==1)
		{
			if(f1==0)
			{
				if(br==1&&bl==1)
				{
					dp[i][f1][f2]=solve(i-1,f1,f2);
				}
				else if(br==1&&bl==0)
				{
					dp[i][f1][f2]=2*solve(i-1,2,f2);
					dp[i][f1][f2]+=solve(i-1,1,f2);
				}
				else if(br==0&&bl==0)
				{
					dp[i][f1][f2]=2*solve(i-1,f1,f2);
				}					
			}
			else if(f1==1)
			{	
				if(br==1)
				{
					dp[i][f1][f2]=2*solve(i-1,3,f2);
					dp[i][f1][f2]+=solve(i-1,f1,f2);
				}
				else
				{
					dp[i][f1][f2]=2*solve(i-1,f1,f2);

				}
			}
			else if(f1==2)
			{
				if(bl==1)
				{
					dp[i][f1][f2]=solve(i-1,f1,f2);
				}
				else
				{
					dp[i][f1][f2]=2*solve(i-1,f1,f2);
					dp[i][f1][f2]+=solve(i-1,3,f2);
				}
			}
			else
			{
				dp[i][f1][f2]=3*solve(i-1,f1,f2);
			}
		}
		else
		{
			if(br1==0)
			{
				if(f1==0)
				{
					if(br==1&&bl==1)
					{
						dp[i][f1][f2]=solve(i-1,f1,f2);
					}
					else if(br==1&&bl==0)
					{
						dp[i][f1][f2]=solve(i-1,2,f2);
						dp[i][f1][f2]+=solve(i-1,1,f2);
					}
					else if(br==0&&bl==0)
					{
						dp[i][f1][f2]=solve(i-1,f1,f2);
					}					
				}
				else if(f1==1)
				{	
					if(br==1)
					{
						dp[i][f1][f2]=solve(i-1,f1,f2);
						dp[i][f1][f2]+=solve(i-1,3,f2);
					}
					else
					{
						dp[i][f1][f2]=solve(i-1,f1,f2);

					}
				}
				else if(f1==2)
				{
					if(bl==1)
					{
						dp[i][f1][f2]=solve(i-1,f1,f2);
					}
					else
					{
						dp[i][f1][f2]=solve(i-1,3,f2);
						dp[i][f1][f2]+=solve(i-1,f1,f2);
					}
				}
				else
				{
					dp[i][f1][f2]=2*solve(i-1,f1,f2);
				}
			}
			else
			{
				if(f1==0)
				{
					if(br==1&&bl==1)
					{
						dp[i][f1][f2]=solve(i-1,f1,1);
					}
					else if(br==1&&bl==0)
					{
						dp[i][f1][f2]=solve(i-1,2,1);
						dp[i][f1][f2]+=solve(i-1,2,0);
						dp[i][f1][f2]+=solve(i-1,1,1);
					}
					else if(br==0&&bl==0)
					{
						dp[i][f1][f2]=solve(i-1,f1,1);
						dp[i][f1][f2]+=solve(i-1,f1,f2);
					}					
				}
				else if(f1==1)
				{	
					if(br==1)
					{
						dp[i][f1][f2]=solve(i-1,3,1);
						dp[i][f1][f2]+=solve(i-1,3,f2);
						dp[i][f1][f2]+=solve(i-1,f1,1);
					}
					else
					{
						dp[i][f1][f2]=solve(i-1,f1,1);
						dp[i][f1][f2]+=solve(i-1,f1,f2);

					}
				}
				else if(f1==2)
				{
					if(bl==1)
					{
						dp[i][f1][f2]=solve(i-1,f1,1);
					}
					else
					{
						dp[i][f1][f2]=solve(i-1,f1,1);
						dp[i][f1][f2]+=solve(i-1,f1,f2);
						dp[i][f1][f2]+=solve(i-1,3,1);
					}
				}
				else
				{
					dp[i][f1][f2]=solve(i-1,f1,1);
					dp[i][f1][f2]+=solve(i-1,f1,1);
					dp[i][f1][f2]+=solve(i-1,f1,f2	);
				}
			}			
		}

	}
	return dp[i][f1][f2];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> l >> r;
		memset(dp,-1,sizeof(dp));
		r1=r;
		ll x=solve(30,0,0);
		ll y=0;
		if(l!=0)
		{
			memset(dp,-1,sizeof(dp));
			r1=l-1;
			y=solve(30,0,0);
		}
		cout<<x-y<<endl;
	}	    
	return 0;
}