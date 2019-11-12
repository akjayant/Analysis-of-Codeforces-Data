#include <bits/stdc++.h>
using namespace std;

#define taskname "TEST"
typedef long long ll;
typedef long double ld;

const int N = 1e3 + 5;

int res, n, a[N], k;

bool cmp(int x, int y) { return x > y; }
void inp() {
    cin >> k;
}
void solve() {
    while (k--) {
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            if (i <= a[i]) res = max(res, i);
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen(taskname".INP", "r", stdin);
  //  freopen(taskname".OUT", "w", stdout);
    inp();
    solve();
}
