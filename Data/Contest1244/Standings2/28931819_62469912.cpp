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
const int N = 1005;

int n;
char s[N];

void run() {
	cin >> n;
	cin >> (s + 1);
	int left = -1, right;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			left = i; break;
		}
	}
	for(int i = n; i >= 1; i--) {
		if(s[i] == '1') {
			right = i; break;
		}
	}
	int ans = 0;
	if(left == -1) {
		ans = n;
	} else {
		ans = max(2 * right, 2 * (n - left + 1));
	}
	cout << ans << '\n';
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
