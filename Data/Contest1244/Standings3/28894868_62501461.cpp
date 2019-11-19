
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const num inf = 0x3f3f3f3f3f3f;
num n, k, mn = inf, mx = -inf;
map<num, num> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cont (i, n) {
        num a;
        cin >> a;
        ++cnt[a];
        mn = min(mn, a);
        mx = max(mx, a);
    }
    num cn = cnt[mn], cx = cnt[mx];
    for (; mn < mx;) {
        if (cx < cn) {
            map<num, num>::iterator it = --cnt.lower_bound(mx);
            num p = it->first, c = it->second, del = cx * (mx - p);
            if (k >= del) {
                k -= del;
                mx = p;
                cx += c;
            } else {
                mx = mx - k / cx;
                k = 0;
            }
        } else {
            map<num, num>::iterator it = cnt.upper_bound(mn);
            num p = it->first, c = it->second, del = cn * (p - mn);
            if (k >= del) {
                k -= del;
                mn = p;
                cn += c;
            } else {
                mn = mn + k / cn;
                k = 0;
            }
        }
        if (!k)  break;
    }
    cout << mx - mn << ln;
}
