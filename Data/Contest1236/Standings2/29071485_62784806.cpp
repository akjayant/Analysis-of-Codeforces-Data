#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while(N--) {
		int a, b, c;
		cin >> a >> b >> c;
		int t = min(c / 2, b);
		b -= t;
		int s = min(b / 2, a);
		cout << (t + s) * 3 << '\n';
	}
}