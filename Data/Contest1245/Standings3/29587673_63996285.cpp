#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++i)

int32_t main() {
    ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    while (Q --> 0) {
        int a, b; cin >> a >> b;
        if(__gcd(a, b) == 1) {
            cout << "Finite\n";
        } else {
            cout << "Infinite\n";
        }
    }
}
