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
#include <bitset>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

int cnt[maxN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q; cin >> Q;
	while (Q--){
		memset(cnt, 0, sizeof cnt);
		int n; cin >> n;
		for (int i = 0; i < n; i++){
			int inp; cin >> inp; cnt[inp]++;
		}
		for (int i = n; i > 1; i--) cnt[i - 1] += cnt[i];
		for (int i = 1; i <= n + 1; i++){
			if (cnt[i] < i) {
				cout << i - 1 << "\n"; break;
			}
		}
		
	}
	return 0;
}
 

