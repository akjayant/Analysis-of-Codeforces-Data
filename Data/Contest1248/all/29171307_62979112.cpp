#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--){
		int n, m; cin >> n;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++){
			int inp; cin >> inp;
			if (inp % 2) cnt1++;
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			int inp; cin >> inp;
			if (inp % 2) cnt2++;
		}
		cout << 1ll * cnt1 * cnt2 + 1ll * (n - cnt1) * (m - cnt2) << "\n";
	}
	return 0;
}
 

