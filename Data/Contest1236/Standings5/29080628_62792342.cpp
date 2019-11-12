#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mpr make_pair
#define mt make_tuple
 
using namespace std;
 
const int N = 100000;
const int mod = 1e9 + 7;
ll power(ll x, ll y, ll p){ ll res = 1; x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;} return res; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,x;
    cin>>n>>m;
    x = power(2,m,mod);
    x = (x - 1 + mod)%mod;
    x = power(x, n, mod);
    cout<<x<<endl;
    return 0;
}