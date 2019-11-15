#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << (gcd(a, b) == 1 ? "Finite\n" : "Infinite\n");
    }
}