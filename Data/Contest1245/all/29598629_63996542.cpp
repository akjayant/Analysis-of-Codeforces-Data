
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

int ts, a, b;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> ts;
    cont (cs, ts) {
        cin >> a >> b;
        if (gcd(a, b) == 1) {
            cout << "Finite" << ln;
        } else {
            cout << "Infinite" << ln;
        }
    }
}