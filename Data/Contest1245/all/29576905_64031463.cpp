#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

ll pw3[33];

ll calc(int c, int a, int b, bool lima, bool limb){
    if (a < 0 || b < 0) return 0;
    // cerr << c << ' ' << a << ' ' << b << ' ' << lima << ' ' << limb << endl;
    if (c < 0) return 1;
    if (lima && limb){
        int ba = (a&(1<<c)), bb = (b&(1<<c));
        if (ba && bb){
            return calc(c-1, a, b, 1, 0) + calc(c-1, a, b, 0, 1) + calc(c-1, a, b, 0, 0);
        } else if (ba || bb){
            if (bb) std::swap(ba, bb), std::swap(lima, limb), std::swap(a, b);
            return calc(c-1, a, b, 1, 1) + calc(c-1, a, b, 0, 1);
        } else {
            return calc(c-1, a, b, 1, 1);
        }
    } else if (lima || limb){
        if (limb) std::swap(lima, limb), std::swap(a, b);
        int ba = (a&(1<<c)), bb = (b&(1<<c));
        if (ba){
            return 2*calc(c-1, a, b, 0, 0) + calc(c-1, a, b, 1, 0);
        } else {
            return 2*calc(c-1, a, b, 1, 0);
        }
    } else {
        return pw3[c+1];
    }
}

ll solve2(int m, int p, int q){
    return calc(31, m, q, 1, 1) - calc(31, m, p-1, 1, 1);
}

ll solve(int l, int r){
    // cerr << solve2(r, l, r) << ' ' << solve2(l-1,l,r) << endl;
    return solve2(r,l,r) - solve2(l-1,l,r);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    pw3[0] = 1;
    for(int i = 1; i < 33; ++i) pw3[i] = pw3[i-1] * 3;
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
