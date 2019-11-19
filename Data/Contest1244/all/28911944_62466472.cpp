#include <bits/stdc++.h>

#define pb push_back
#define debug(x) cout << #x << "  :  " << x


using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans = (a + c - 1) / c + (b + d - 1) / d;
        if (ans <= k ) {
            cout << (a + c - 1) /c  << ' ' << (b + d - 1) / d << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}