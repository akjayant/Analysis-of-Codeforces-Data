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

int a[maxN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll x = 0, y = 0;
	for (int i = 0; i < n / 2; i++) x += a[i];
	for (int i = 0; i < n / 2; i++) y += a[n - 1 - i];
	if (n % 2 == 0) return cout << x * x + y * y << endl, 0;
	ll mx = max((x + a[n / 2]) * (x + a[n / 2]) + y * y, (y + a[n / 2]) * (y + a[n / 2]) + x * x);
	cout << mx << endl;
	return 0;
}
 

