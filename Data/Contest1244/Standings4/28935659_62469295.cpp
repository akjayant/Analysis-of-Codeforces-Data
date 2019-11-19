#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef long long         ll;
typedef pair<int, int>    pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define all(a)      a.begin(), a.end()
#define ff          first
#define ss          second
#define pb          push_back
#define eps         1e-9
#define inf         (1000000000)
#define infl        (1000000000000000000LL)
#define SET(a)      memset((a), -1, sizeof(a))
#define CLR(a)      memset((a), 0, sizeof(a))
#define pil vector<int, pii>

random_device rand_dev;
mt19937 generator(rand_dev());
uniform_int_distribution<ll> distr(0ll, 1000000000000000000ll);

int main() {
	int a, b, c, d, k;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mi = n + 1, mx = -1;
		int i = 0;
		for(auto u : s){
			i++;
		  	if(u == '1') mi = min(mi, i), mx = max(mx, i);
		}
		if(mi == n + 1) cout << n << endl;
		else cout << max(2 * n - 2 * (mi - 1), 2 * mx) << endl;
	}

}
