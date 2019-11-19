#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
 
#define mp make_pair
#define pb push_back
#define tri pair<int, pair<int, int> >
#define TRI(a,b,c) (make_pair(a,make_pair(b,c)))
 
typedef long long ll;
typedef long double ld;

ll powmod(ll x, ll y, ll m=M)
{
	if(y==0) return 1;
	ll ret = powmod(x, y/2, m);
	ret = (ret*ret)%m;
	if(y%2) ret=(ret*x)%m;
	return ret;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k; cin>>n>>k;
    vector<ll> vec(n);
    for(int i=0; i<n; i++)
    {
    	cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    ll l=0, r = n-1, tmp;
    while(l!=r && k >= min(l+1, n-r))
    {
    	if(vec[l]==vec[l+1]) l++;
    	else if(vec[r]==vec[r-1]) r--;
    	else
    	{
    		if(l+1 <= n-r)
    		{
    			tmp = min((k/(l+1)), vec[l+1]-vec[l]);  
    			k -= tmp*(l+1);
    			vec[l] += tmp;
    		}
    		else
    		{
    			tmp = min((k/(n-r)), vec[r]-vec[r-1]);
    			k -= tmp*(n-r);
    			vec[r] -= tmp;
    		}
    	}
    }
    cout<<vec[r] - vec[l];
    return 0;
}