#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;

        cin >> a >> b >> c >> d >> k;
        int needed_pens = (a + c - 1) / c;
        int needed_penc = (b + d - 1) / d;
        bool yes = 0;
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i >= needed_pens && j >= needed_penc) {
                yes = 1;
                cout << i << ' ' << j << '\n';
                break;
            }
        }
        if (!yes)
            cout << -1 << "\n";
    }
    return 0;
}