#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
 
void testCase() {
    ll n;
    cin >> n;
    vector <ll> div;
    for (ll i=2; i*i <= n; i++) {
        if (n%i == 0) {
            if (n/i == i) {
                div.push_back (i);
            }
            else {
                div.push_back (i);
                if (n/i != n || n/i != 1) {
                    div.push_back (n/i);
                }
            }
        }
    }
    if (div.size() == 0) {
        cout << n << endl;
    }
    else {
        ll ans = 0;
        for (int i=0; i<div.size(); i++) {
            ans = __gcd (ans, div[i]);
        }      
        cout << ans << endl;
    }
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}