//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}
std::vector<ll> v1[100002];
std::vector<ll> ver;
ll fl=0;
void dfs(ll x,ll par)
{
	if(v1[x].size()>2)
	{
		fl=1;
		return;
	}
	// cout<<x<<'\n';
	ver.pb(x);
	for (int i = 0; i < v1[x].size(); ++i)
	{
		if(v1[x][i]!=par)
		{
			// cout<<v[x][i]<<'\n';
			dfs(v1[x][i],x);
		}
	}
	return;
}
ll dp[100002][5][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll a[100002],b[100002],c[100002];
   for (int i = 1; i <=n; ++i)
   {
   	ll x;
   	cin>>a[i];
   }
   for (int i = 1; i <=n; ++i)
   {
   	ll x;
   	cin>>b[i];
   	// b.pb(x);
   }
   for (int i = 1; i <=n; ++i)
   {
   	ll x;
   	cin>>c[i];
   	// c.pb(x);
   }
    for (int i = 0; i < n-1; ++i)
    {
    	ll a,b;
    	cin>>a>>b;
    	v1[a].pb(b);
    	v1[b].pb(a);
    }
    for (int i = 1; i <= n; ++i)
    {
    	if(v1[i].size()==1)
    	{
    		// cout<<i<<" ";
    		dfs(i,-1);
    		break;
    	}
    }
    if(fl==1)
    {
    	cout<<"-1"<<'\n';
    	return 0;
    }
    std::vector<ll> v[10];
    // for (int i = 0; i < 6; ++i)
    // {
    // 	v[1]
    // }
    v[1].pb(1);
    v[1].pb(2);
    v[1].pb(3);
    v[2].pb(1);
    v[2].pb(3);
    v[2].pb(2);
    v[3].pb(2);
    v[3].pb(1);
    v[3].pb(3);
    v[4].pb(2);
    v[4].pb(3);
    v[4].pb(1);
    v[5].pb(3);
    v[5].pb(1);
    v[5].pb(2);
    v[6].pb(3);
    v[6].pb(2);
    v[6].pb(1);
    ll min=1e18,index=-1;
    for (int i = 1; i <7; ++i)
    {
    	ll kk=0;
    	ll tot=0;
    	// cout<<i<<'\n';
    	for (int j = 0; j < ver.size(); ++j)
    	{
    		// cout<<v[i][kk]<<" "<<ver[j]<<'\n';
    		if(v[i][kk]==1)
    		{
    			tot+=a[ver[j]];
    		}
    		else if(v[i][kk]==2)
    		{
    			tot+=b[ver[j]];
    		}
    		else
    		{
    			tot+=c[ver[j]];
    		}
    		kk++;
    		kk=kk%3;
    	}
    	// cout<<tot<<'\n';
    	if(tot<min)
    	{
    		min=tot;
    		index=i;
    	}
    }
    cout<<min<<'\n';
    ll col[100002];
    ll kk=0;
    for (int i = 0; i < ver.size(); ++i)
    {
    	col[ver[i]]=v[index][kk];
    	kk++;
    	kk=kk%3;
    }
    for (int i = 1; i <=n; ++i)
    {
    	cout<<col[i]<<" ";
    }
    cout<<'\n';
    // dp[ver[0]][1][0]=a[ver[0]];
    // dp[ver[0]][2][0]=b[ver[0]];
    // dp[ver[0]][3][0]=c[ver[0]];
    // dp[ver[1]][1][2]=a[ver[1]]+b[ver[0]];
    // dp[ver[1]][1][3]=a[ver[1]]+c[ver[0]];
    // cout<<ver[0]<<'\n';
    // cout<<dp[ver[1]][1][3]<<" "<<ver[1]<<'\n';
    // dp[ver[1]][2][1]=b[ver[1]]+a[ver[0]];
    // dp[ver[1]][2][3]=b[ver[1]]+c[ver[0]];
    // dp[ver[1]][3][1]=c[ver[0]]+a[ver[1]];
    // dp[ver[1]][3][2]=c[ver[0]]+b[ver[1]];
    // for (int i = 2; i < ver.size(); ++i)
    // {
    // 	dp[ver[i]][1][2]=dp[ver[i-1]][2][3]+a[ver[i]];
    // 	dp[ver[i]][1][3]=dp[ver[i-1]][3][2]+a[ver[i]];
    // 	dp[ver[i]][2][1]=dp[ver[i-1]][1][3]+b[ver[i]];
    // 	dp[ver[i]][2][3]=dp[ver[i-1]][3][1]+b[ver[i]];
    // 	dp[ver[i]][3][1]=dp[ver[i-1]][1][2]+c[ver[i]];
    // 	dp[ver[i]][3][2]=dp[ver[i-1]][2][1]+c[ver[i]];
    // }
    // cout<<dp[ver[ver.size()-1]][1][3]<<'\n';
    // cout<<min({dp[ver[ver.size()-1]][1][2],dp[ver[ver.size()-1]][1][3],dp[ver[ver.size()-1]][2][1],dp[ver[ver.size()-1]][2][3],dp[ver[ver.size()-1]][3][1],dp[ver[ver.size()-1]][3][2]});
}
