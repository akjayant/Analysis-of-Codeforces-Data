#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e6 + 100;
const ll mod = 1e9 + 7;
bitset <sz> fl;
vector <ll> pr;

void siv() {
    for (int i = 4; i < sz; i+=2) fl[i] = i;
    for (int i = 3; i * i < sz; i+=2) {
        if (fl[i]) continue;
        for (int j = i * i; j < sz; j+=i) {
            fl[j] = 1;
        }
    }
    pr.push_back(2ll);
    for (ll i = 3; i < sz; i+=2) {
        if (fl[i] == 0) pr.push_back(i);
    }
}
 

int main() {

    siv();

    ll n;

    while (cin >> n) {

        vector <ll> prms;

        for (const ll& x: pr) {
            if (n % x == 0) {
                prms.push_back(x);
            }
            while (n % x == 0) {
                n /= x;
            }
        }

        if (n != 1) {
            prms.push_back(n);
        }

        if (prms.size() == 1) {
            cout << prms.front() << "\n";
        } else {
            cout << 1 << "\n";
        }

    }

    return 0;
}