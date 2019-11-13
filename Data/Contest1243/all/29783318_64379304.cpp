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
int n, m, k, t;
int a[N];
string ss;

main (){
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int ii = 0; ii < t; ii++){
		cin >> n;
		int col = 0;
		string s1, s2;
		cin >> s1 >> s2;
		vector <int> v;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i]){
				col++;
				v.pb(i);
			}
		}
		if (col == 0){
			cout << "YES\n";
			con;
		}
		if (col == 2){
			swap(s1[v[0]], s2[v[1]]);
			if (s1 == s2){
				cout << "YES\n";
				con;
			}
			else{
				cout << "NO\n";
				con;
			}
		}
		cout << "NO\n";
	}
	
	return 0;
}










