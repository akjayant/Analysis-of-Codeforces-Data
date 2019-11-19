#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint MOD = 1e9 + 7;

int main() {
    llint a,b,c,d,k;
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d >> k;
        llint x = (a - 1) / c + 1, y = (b - 1) / d + 1;
        if(x + y <= k) {
            cout << x << " " << y << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}