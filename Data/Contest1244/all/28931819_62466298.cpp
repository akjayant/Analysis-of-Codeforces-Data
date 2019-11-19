#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
// #define Local
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int a, b, c, d, k;

void run() {
	cin >> a >> b >> c >> d >> k;
	for(int x = 1; x < k; x++) {
		int y = k - x;
		if(x * c >= a && y * d >= b) {
			cout << x << ' ' << y << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    int T; cin >> T;
    while(T--) run();
    return 0;
}
