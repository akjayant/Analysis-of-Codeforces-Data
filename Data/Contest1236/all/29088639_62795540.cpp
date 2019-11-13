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
const int N = 305;

int n;
int mp[N][N];

void run() {
	cin >> n;
	for(int j = 1; j <= n; j++) {
		int st = (j - 1) * n + 1;
		if(j & 1) {
			for(int i = n; i >= 1; i--, st++) {
				mp[i][j] = st;
			}
		} else {
			for(int i = 1; i <= n; i++, st++) {
				mp[i][j] = st;
			}			
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << mp[i][j] << " \n"[j == n];
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
#ifdef Local
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    while(cin >> n) run();
    return 0;
}
