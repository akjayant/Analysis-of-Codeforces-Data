#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (ll d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            ll nc = n;
            while (nc % d == 0)
                nc /= d;
            if (nc == 1)
                cout << d << endl;
            else
                cout << 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}