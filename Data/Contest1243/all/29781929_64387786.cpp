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
const ll N = 100005;
const ll M = 1e9 + 7;
void solve(){
	ll n;
	cin >> n;
	ll x = n;
	vector < ll > v;
	for(ll i = 2; i <= 1e6; i++){
		if(n%i == 0){
			v.pb(i);
			while(n%i == 0) n = n/i;
		}
	}
	if(n > 1) v.pb(n);
	if(v.size() == 1) cout << v[0] << "\n";
	else cout << 1 << "\n";
	return ;
}
int main(){
    fastio;
    int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}