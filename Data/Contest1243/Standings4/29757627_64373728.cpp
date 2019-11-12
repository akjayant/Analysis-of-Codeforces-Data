#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int q, n, a[N];

int main(){



    cin >> q;
    while (q--){
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort (a + 1, a  + n + 1);
        int ans = 0;
        for (int i = n; i >= 1; --i){
            if (n - i + 1 > a[i]) break;
            ans = max (ans, min (n - i + 1, a[i]));
        }
        cout << ans << '\n';
    }


}
