#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g;
int n, m, k;
int a[N];
string ss;
map <int, int> M;

main (){
	ios_base::sync_with_stdio(0);
	cin >> n;
	k = n;
	vector <int> v;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			v.pb(i);
		}
		while (n % i == 0){
			n /= i;
			M[i]++;
		}
	}
	if (n != 1){
		v.pb(n);
		M[n] = 1;
	}
	if (v.size() == 1)cout << v[0];
	else cout << 1;
	return 0;
}










