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

	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		ll g = __gcd(a, b);
		if(g == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}

	return 0;
			
}