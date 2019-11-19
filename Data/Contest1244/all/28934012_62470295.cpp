#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 1e5 + 5;
const int INF = 1e9 + 5;
const int base = 1e4;

typedef long long ll;

const ll mod = 1e9 + 7;

int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int b = -1, a = n, ct = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ct++;
                if (a == n)
                    a = i;
                b = i;
            }
        }
        cout << max(n + ct, max((b + 1) * 2, (n - a) * 2)) << "\n";
    }
}
