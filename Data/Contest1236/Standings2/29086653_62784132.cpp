#include <bits/stdc++.h>

using namespace std;

#define long long long int 

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0;
        while (b >= 1 && c >= 2) {
            res += 3;
            b--;
            c -= 2;
        }
        while (a >= 1 && b >= 2) {
            res += 3;
            a--;
            b -= 2;
        }
        cout << res << "\n";
    }

   
    return 0;
}