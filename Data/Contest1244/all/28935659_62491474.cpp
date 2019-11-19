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
ordered_set S;

#define all(a)      a.begin(), a.end()
#define ff          first
#define ss          second
#define pb          push_back
#define SET(a)      memset((a), -1, sizeof(a))
#define CLR(a)      memset((a), 0, sizeof(a))


ll n, k;
ll a[100009];
ll sf[100009], sd[100009];


bool Pos(ll d){
	ll i;

	for(i = 1; i <= n; i++){
		ll ka, kb;

		ll	big = lower_bound(a, a + n + 1, a[i]) - a - 1;
		ka = big * a[i] - sf[big];

		ll endd = upper_bound(a, a + n + 1, a[i] + d) - a;
		kb = sd[endd] - (n - endd + 1) * (a[i] + d);
//		cout << ka << " " << kb << endl;

		if(ka + kb <= k){
//			cout << a[i] << ' ' << i << endl;
			return 1;
		}

		big = upper_bound(a, a + n + 1, a[i] - d - 1) - a - 1;
		ka = big * (a[i] - d) - sf[big];

		endd = upper_bound(a, a + n + 1, a[i]) - a;
		kb = sd[endd] - (n - endd + 1) * (a[i]);
//		cout << ka << " " << kb << endl;

		if(ka + kb <= k){
//			cout << a[i] << ' ' << i << endl;
			return 1;
		}
	}
	return 0;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
	ll i, j;
	cin  >> n >> k;
	for(i = 1; i <= n; i++) cin >> a[i] ;
	sort(a, a + n + 1);
	for(i = 1; i <= n; i++){
		sf[i] = a[i] + sf[i - 1];
	}
	for(i = n; i >= 1; i--){
		sd[i] = a[i] + sd[i + 1];
	}


	ll in = -1, fi = a[n] - a[1] + 1, mi = (in + fi) / 2;

	while(in != fi - 1){
		if(Pos(mi)) fi = mi;
		else in = mi;
		mi = (in + fi) / 2;
	}
	cout << fi << endl;
}
