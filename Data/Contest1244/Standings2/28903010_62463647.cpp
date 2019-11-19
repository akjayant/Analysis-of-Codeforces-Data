#include <bits/stdc++.h>
 
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("anime.in", "r", stdin); freopen("anime.out", "w", stdout);

typedef long long ll;
typedef long double ld;
 
using namespace std;

signed main(){
	ios;
	int t, a, b, c, d, k;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d >> k;
		int r = (a + c - 1) / c;
		int kar = (b + d - 1) / d;
		if (r + kar > k){
			cout << -1 << endl;
		}else{
			kar = k - r;
			cout << r << ' ' << kar << endl;
		}
	}
}