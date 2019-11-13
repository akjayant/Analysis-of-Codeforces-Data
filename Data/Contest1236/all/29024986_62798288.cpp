#include<bits/stdc++.h>
using namespace std;
#define ll       long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define god         10000000000000007
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define M_PI 3.14159265358979323846
#define fastio iostream::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll power(ll x, ll y, ll p){ ll res = 1;x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p;y = y>>1;x = (x*x) % p;} return res%p; }

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() > second.size();
    }
};


int main()
{
    
	fastio;
	ll n;
	cin>>n;
	std::vector<ll> v;
	ll c=1;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
			v.push_back(c++);
	}
	ll flag=0;
	for (int i = 0; i < n; ++i)
	{
		if(flag)
			reverse(v.begin()+i*n,v.begin()+(i+1)*n);
		flag=1-flag;
	}
	ll k=0;
	ll a[n][n];
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
			a[i][j]=v[k++];
		
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<a[i][j]<<" ";
	// 	cout<<endl;
	// }
	for (int i = 0; i < n; ++i)
	{
		for(int j=i;j<n;j++)
			swap(a[i][j],a[j][i]);
	}

	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
	
   

};
		