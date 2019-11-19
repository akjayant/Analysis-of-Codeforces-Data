#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 LL;
//typedef unsigned long long ull;
//#define F first
//#define S second
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
const ld PI=acos(-1);
const ld eps=1e-9;
//unordered_map<int,int>mp;
#define ls (o<<1)
#define rs (o<<1|1)
#define pb push_back
const int seed=131;
const int M = 1e5+7;
int p[M];
int q[M];
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int t;
  	cin>>t;
  	while(t--)
  	{
  		int n,m;
  		cin>>n;
  		int ji=0,ou=0;
  		for(int i=1;i<=n;i++)
  		{
  			cin>>p[i];
			if(p[i]&1)ji++;
			else ou++;
		  } 
		  	
		cin>>m;
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>q[i];
			if(q[i]&1)ans+=ji;
			else ans+=ou;
		}
		cout<<ans<<endl; 
	  }
	 
	return 0;
}