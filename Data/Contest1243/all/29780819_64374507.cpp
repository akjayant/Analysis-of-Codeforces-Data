#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
int a[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            if (min(i + 1, a[n - i - 1]) >= i + 1) {
                ma = i + 1;
            }
        }
        cout << ma << '\n';
    }


}