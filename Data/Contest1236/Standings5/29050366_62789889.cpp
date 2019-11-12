#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
ll mod = 1000000007;
ll raise(ll a, ll n){
  if(n == 0)return 1;
  if(n == 1)return a;
  ll x = 1;
    x *= raise(a,n/2);
    x %= mod;
    x *= x;
    x %= mod;
    if(n%2)x*= a;
    x %= mod;
    return x;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m, t;
	cin>>n>>m;
	n %= mod;
	t = raise(2, m) - 1;
	ll r = raise(t, n);
	r %= mod;
	cout<<r;
}