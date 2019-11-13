#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef pair <int, pii> piii;
#define fr first
#define sc second
#define pb push_back
#define ppb pop_back()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define mpr make_pair
const int mod = 1e9 + 7;
ll bp(ll x, ll y){
	if(!y)return 1;
	ll res = 1;
	if(y % 2 == 1)res = x;
	return (res * bp((x * x) % mod, y / 2)) % mod;
}
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << bp((bp(2, m) - 1 + mod) % mod, n);
	return 0;
}