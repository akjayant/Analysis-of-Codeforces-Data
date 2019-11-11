#include <bits/stdc++.h>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a == 1 || b == 1)cout << "Finite\n";
        else if(a == b)cout << "Infinite\n";
        else {
            if(__gcd(a, b) == 1) cout << "Finite\n";
            else cout << "Infinite\n";
        }
    }
}
