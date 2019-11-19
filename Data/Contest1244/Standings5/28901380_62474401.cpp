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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        bool has_door = false;
        ll min_ = -1;
        ll max_ = -1;
        for (ll i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (!has_door) {
                    has_door = true;
                    min_ = i;
                }
                max_ = i;
            }
        }
        ll res;
        if (has_door) {
            res = 2 * std::max<ll>(max_ + 1, s.size() - min_);
        } else {
            res = n;
        }
        cout << res << endl;
    }
    return 0;
}
