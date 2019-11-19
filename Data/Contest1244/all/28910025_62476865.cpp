#include <bits/stdc++.h>
#define N ((int)1e6+10)
#define MD ((int)1e9+7)

using namespace std;
long long n, p, d, w, x, y, z;

int main() {
    string s;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> w >> d;

    if (p == 0) {
        cout << 0 << " " << 0 << " " << n << endl;
        return 0;
    }
    bool yes = false;
    long long pp = p;
    for (int i = 1; i < 1e5 + 10; i++) {
        if (p % d == 0) {
            y = p / d;
            z = n - y - x;
            if (z >= 0 && x + y + z == n) {
                yes = true;
                break;
            }
        }
        if (p - w >= 0) {
            p -= w;
            x++;
        }
    }
    if (yes) {
        cout << x << " " << y << " " << z << endl;
        return 0;
    }
    x = y = z = 0;
    p = pp;
    yes = false;
    for (int i = 1; i < 1e5 + 10; i++) {
        if (p % w == 0) {
            x = p / w;
            z = n - y - x;
            if (z >= 0 && x + y + z == n) {
                yes = true;
                break;
            }
        }
        if (p - d >= 0) {
            p -= d;
            y++;
        }
    }
    if (yes) {
        cout << x << " " << y << " " << z << endl;
        return 0;
    }
    cout << -1 << endl;


    return 0;
}
