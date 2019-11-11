#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ll> point;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const ll mod = 1e9 + 7;
	const int maxn = 2e5 + 5;


	vector<ll> f(maxn);

	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i < maxn; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;


	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
	}

	s += "?";

	ll ans = 1;
	ll cnt = 1;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i - 1])
			cnt++;
		else{

			if(s[i - 1] == 'n' || s[i - 1] == 'u'){
				ans = (ans * f[cnt]) % mod;
			}

			cnt = 1;
		}
	}

	cout << ans << endl;

	return 0;
}