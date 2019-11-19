#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#define rep(x,y,z) for(long long x=y;x<z;++x)
#define dwn(x,y,z) for(long long x=y;x>z;--x)
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    rep(q,0,t) {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll x = (a + c - 1) / c;
        ll y = (b + d - 1) / d;
        if (x + y > k) {
            cout << -1 << endl;
        } else {
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
