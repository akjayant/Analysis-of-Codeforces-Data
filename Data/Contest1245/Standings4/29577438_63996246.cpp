#include<bits/stdc++.h>


using namespace std;

const int N = 1e6 + 2, MOD = 998244353;

#define ss second
#define ff first
#define int long long

using vi = vector <int>;
using vp = vector <pair <int, int>>;


signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) {
            cout << "Finite\n";
        }
        else cout << "Infinite\n";
    }
}
