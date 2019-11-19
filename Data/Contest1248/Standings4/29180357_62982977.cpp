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

int n;
vector<ll> a;
ll tot, av, dist2;


int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
//   ifstream cin("/Users/konwoo/input.txt");
 //   ofstream cout("/Users/konwoo/output.txt");

	 cin >> n;
	 F0R(i,n){
		 cin >> av;
		 tot += av;
		 a.pb(av);
	 }
	 sort(all(a));
	 reverse(all(a));
	 F0R(i, (n+1)/2){
		 tot -= a[i];
		 dist2 += a[i];
	 }
	 tot = 1LL * tot * tot;
	 dist2 = 1LL * dist2 * dist2;
	 tot = tot + dist2;
	 cout << tot << newl;



	 



    return 0;
}
