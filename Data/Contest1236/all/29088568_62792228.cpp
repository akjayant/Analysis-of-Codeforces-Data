#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const ll mod=1e9+7;
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 
int main()
{
	ll n,m;
	cin>>n>>m;
	ll k = power(2LL,m,mod);
	k--;
	if(k<0)
		k+=mod;
	cout<<power(k,n,mod)<<endl;
	return 0;
}