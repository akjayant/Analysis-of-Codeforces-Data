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

    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }

    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        int r = i + 1;
        int l = -a[i];

        ans = max(ans, min(l, r));
    }
    cout << ans << "\n";
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
