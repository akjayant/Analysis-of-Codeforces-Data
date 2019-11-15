#include <bits/stdc++.h>
using namespace std;

#define int long long

main() {
    int test;
    cin >> test;
    while(test--) {
        int a, b;
        cin >> a >> b;
        if(__gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}
