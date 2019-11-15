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
		vector <pair <int, int >> v;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i]){
				//cout << "asd";
				char w = s1[i];
				for (int j = i + 1; j < s1.size(); j++){
					if (s1[j] == w){
						v.pb(mp(j, i));
						swap(s2[i], s1[j]);
						break;
					}
					if (s2[j] == w){
						v.pb({j,j});
						v.pb({j, i});
						swap(s1[j], s2[j]);
						swap(s2[i], s1[j]);
						break;
					}
				}
			}
			//break;
		}
		//cout << s1 << " " << s2 << endl;
		if (s1 != s2){
			cout << "No\n";
			con; 
		}
		cout << "Yes\n";
		cout << v.size() << endl;
		for (auto i: v){
			cout << i.f + 1 << " " << i.s + 1 << endl;
		}
	}
	
	return 0;
}










