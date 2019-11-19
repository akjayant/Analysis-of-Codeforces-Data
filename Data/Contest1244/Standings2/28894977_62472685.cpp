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

main (){
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int ii = 0; ii < tt; ii++){
		cin >> n >> ss;
		int col = 0, l = -1, r;
		for (int i = 0; i < ss.size(); i++){
			if (ss[i] == '1'){
				col++;
				if (l == -1){
					l = i;
				}
				r = i;
			}
		}
		if (col == 0){
			cout << ss.size();
		}
		else if (col == 1){
			cout << max(max(l + l + 2, n), (n - l) * 2);
		}
		else {
			cout << max((n - l) * 2, max(r + 1 + r + 1, n));			
		}
		cout << endl;
	}
	
	return 0;
}










