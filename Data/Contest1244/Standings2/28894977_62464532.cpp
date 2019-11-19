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

main (){
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; i++){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		a = (a + c - 1)  / c;
		b = (b + d - 1) / d;
		if (a + b > k){
			cout << -1;
		}
		else{
			cout <<a << " " << b;
		}
		cout << endl;
	}
	
	return 0;
}










