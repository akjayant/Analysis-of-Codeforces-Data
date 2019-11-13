#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector <int> sw;
    for(int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            sw.push_back(i);
        }
    }

    if (sw.size() > 1) {
        swap(s[sw[0]], t[sw[1]]);
    }

    cout << (s == t ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test;
    cin >> test;

    while(test--) {
        solve();
    }

    return 0;
}
/*
*/
