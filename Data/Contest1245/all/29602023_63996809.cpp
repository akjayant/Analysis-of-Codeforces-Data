#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int g = __gcd(a, b);
        if (g == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}
