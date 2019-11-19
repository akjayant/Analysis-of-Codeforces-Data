#include <bits/stdc++.h>
#define ll long long
#define lf long double
#define INF 1000000000
#define MAX 1000001
#define M 1000000007
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n;
        ll e1 = 0, o1 = 0;
        for (ll i=0;i<n;i++) {
            ll x;
            cin >> x;
            if (x%2==0) e1++;
            else o1++;
        }
        cin >> m;
        ll res = 0;
        for (ll i=0;i<m;i++) {
            ll x;
            cin >> x;
            if (x%2==0) res+=e1;
            else res+=o1;
        }
        cout << res << endl;
    }
    return 0;
}