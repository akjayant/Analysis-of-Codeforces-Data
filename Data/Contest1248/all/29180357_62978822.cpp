#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;


#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i>=0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define f first
#define s second
#define newl '\n'
#define mp make_pair
#define trav(a,b) for (auto& a : b)


const int MX = 2e5 + 5;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = 998244853;

int t, n, p[MX], q[MX], m;
ll ans, pp[2], qq[2];
 
int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
//   ifstream cin("/Users/konwoo/input.txt");
 //   ofstream cout("/Users/konwoo/output.txt");

	 cin >> t;
	 F0R(i,t){
		 cin >> n;
		 pp[0] = 0;
		 pp[1] = 0;
		 qq[0] = 0;
		 qq[1] = 0;
		 ans = 0;
		 F0R(j,n){
			 cin >> p[j];
			 pp[(p[j] % 2)]++;
		 }
		 cin >> m;
		 F0R(j, m){
			 cin >> q[j];
			 qq[(q[j] % 2)]++;
		 }
		 ll tmp = n;
		 ll tmp2 = m;
		 ans = tmp * tmp2;
		 ans -= (pp[0] * qq[1] + pp[1] * qq[0]);
		 cout << ans << newl;
	 }



    return 0;
}
