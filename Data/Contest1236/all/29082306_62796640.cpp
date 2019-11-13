#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end()
#define endl '\n'
#define show(a) for(auto i:a) cout<<i<<" ";cout<<endl
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< int , int > mypair;
typedef priority_queue <int> max_heap;
typedef priority_queue <int, vector<int>, greater<int> > min_heap;
const ll mod=1e9+7;
const ll inf=1e9;
const ll N=5e5+10;

ll mod_expo(ll a,ll b, ll c)
{
	ll ans=1;
	while(b)
	{
		if(b & (ll)1) ans=(ans*a)%c;
		a=(a*a)%c;
		b=b>>1;
	}
	return ans;
}
ll inverse(ll n)
{
	return mod_expo(n,mod-2,mod);
}


int main()
{
	boost;
	int n;
	cin>>n;
	vector<int > v[n+1];
	int now=1;
	for(int i=0;i<n;i++)
	{
		if(i%2)for(int j=1;j<=n;j++)
		{
			v[j].pb(now);
			now++;

		}
		else
		for(int j=n;j>=1;j--)
		{
			v[j].pb(now);
			now++;
		}			
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:v[i]) cout<<j<<" ";
		cout<<endl;	
	}
   	return 0;
}