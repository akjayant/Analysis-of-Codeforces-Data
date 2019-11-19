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
const int N = 1e5 + 1, mod = 1e9 + 7;
ll d[N][2];
ll res(int n){
	for(int i = 1;i <= n; ++ i)d[i][0] = d[i][1] = 0;
	d[1][0] = 2;
	for(int i = 2;i <= n; ++ i){
		d[i][1] = d[i - 1][0];
		d[i][0] = (d[i - 1][0] + d[i - 1][1]) % mod;
	}
	return (d[n][1] + d[n][0]) % mod;
}
int n, m;
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cout << (res(n) + res(m) - 2 + mod) % mod;
	return 0;
}