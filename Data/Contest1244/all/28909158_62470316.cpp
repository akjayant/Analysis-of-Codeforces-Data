#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.get();
        string str;
        getline(cin, str);
        int first = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                first = i;
                break;
            }
        }
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '1') {
                last = i;
                break;
            }
        }

        if (first == -1) {
            cout << n << "\n";
        } else {
            if (first == 0 || last == n - 1) {
                cout << 2 * n << "\n";
                continue;
            }
            int dif1 = first;
            int dif2 = n - 1 - last;
            cout << max(max(dif1, n - dif1), max(dif2, n - dif2)) * 2 << "\n";
        }
    }
}

int main() {
	//~ freopen(".in", "r", stdin);
	//~ freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
    solve();
    return 0;
}
