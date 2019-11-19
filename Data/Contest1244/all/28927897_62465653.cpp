#include <bits/stdc++.h>

using namespace std;

int main () {
    long long int q;
    cin >> q;
    while(q--) {
        long long int a, b, c, d, k, p1, p2;
        cin >> a >> b >> c >> d >> k;
        p1=(a+c-1)/c;
        p2=(b+d-1)/d;
        if(p1+p2<=k)
            cout << p1 << ' ' << p2 << '\n';
        else
            cout << -1 << '\n';
    }
}
