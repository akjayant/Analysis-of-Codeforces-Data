#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define cl clear
#define in insert
#define er erase
#define S second
#define F first
#define endl "\n" 
#define all(v) (v).begin(), (v).end()
#define getbit(x, i) ((x >> i)&1)
#define sz(v) (v).size()
#define fr(i, a, b, d) for(ll i = a; i < b; i+= d)
#define frr(i, a, b, d) for(ll i = a; i >= b; i -= d)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define pll pair < ll, ll >
#define pii pair < int, int >
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n";
using namespace std;
const int N = 20;
const ll M = 1e9 + 7;
ll modexpo(ll x, ll p){
	ll ans = 1;
	while(p>0){
		if(p&1) ans = (ans*x)%M;
		p = p/2;
		x = (x*x)%M;
	}
	return ans;
}
int main(){
	ll n, m;
	cin >> n >> m;
	cout << modexpo((modexpo(2, m) - 1 + M)%M, n);
	return 0;
}