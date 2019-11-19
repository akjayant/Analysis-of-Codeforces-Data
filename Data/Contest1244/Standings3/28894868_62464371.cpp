
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

int ts;
int a, b, c, d, k;

int main() {
    cin >> ts;
    cont (cs, ts) {
        cin >> a >> b >> c >> d >> k;
        int r1 = -1, r2 = -1;
        circ (i, 0, k) {
            int j = k - i;
            if (i * c >= a && j * d >= b) {
                r1 = i, r2 = j;
                break;
            }
        }
        if (r1 == -1) {
            cout << -1 << ln;
        } else {
            cout << r1 << ' ' << r2 << ln;
        }
    }
}
