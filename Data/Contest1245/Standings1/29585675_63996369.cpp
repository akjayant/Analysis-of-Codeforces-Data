#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll n, p;
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        if (__gcd(x, y) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }

}
 