#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int inf = 1e9 + 7;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int y = 0; y < t; ++y) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        int cnt = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= cnt + 1) ++cnt;
            else break;
        }
        cout << cnt << endl;
    }
    return 0;
}