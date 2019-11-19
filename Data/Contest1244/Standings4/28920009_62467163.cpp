#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int l = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }

    int r = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            r = i;
        }
    }

    if (l == -1) {
        cout << n << "\n";
    }
    else {
        cout << max(n - l, r + 1) * 2 << "\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
/*
*/
