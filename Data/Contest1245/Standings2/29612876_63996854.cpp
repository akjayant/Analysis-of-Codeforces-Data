#include <bits/stdc++.h>
#define E 0.000000000001
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;
 
int main() {
    ios_base:: sync_with_stdio(false);
    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        if(__gcd(a, b) != 1) cout << "Infinite\n";
        else cout << "Finite\n";
    }
}
 