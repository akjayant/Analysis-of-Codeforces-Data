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

ll gcdExtended(ll a, ll b, ll *x, ll *y)  
{
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  

    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, p, w, d; cin>>n>>p>>w>>d;
    if(p%w == 0 && p/w <= n)
    {
    	cout<<p/w<<" 0 "<<n-p/w;
    	return 0;
    }
    else if(p%d == 0 && p/d <= n)
    {
    	cout<<"0 "<<p/d<<" "<<n-p/d;
    	return 0;
    }
    ll g = __gcd(w, d);
    if(p%g != 0)
    {
    	cout<<-1;
    	return 0;
    }
    w/=g;
    d/=g;
    p/=g;
    ll x, y;
    g = gcdExtended(d, w, &x, &y);
    x = (x+w*w)%w;
    y = (x*(p%w))%w;
    if(d*y > p)
    {
    	cout<<-1;
    	return 0;
    }
    x = (p-d*y)/w;
    if(x+y > n || x < 0)
    {
    	cout<<-1;
    	return 0;
    }
    cout<<x<<" "<<y<<" "<<n-x-y;
    return 0;
}