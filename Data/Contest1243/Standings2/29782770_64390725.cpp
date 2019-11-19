#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0 && n >= i) {
                n /= i;
            }
            if(n == 1) cout << i << endl;
            else cout << 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
