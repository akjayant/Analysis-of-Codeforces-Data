#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int res = 0;
        for(int i=0; i<=a; ++i) {
            if(2 * i > b) break;
            int tmp = 3 * i + 3 * min(b - 2 * i, c / 2);
            res = max(res, tmp);
        }
        cout << res << '\n';
    }
}