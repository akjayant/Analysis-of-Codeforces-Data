#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;  
        cin >> a >> b >> c;
        int ans = min(c/2, b);
        b -= ans;
        ans += min(a, b/2);
        cout << 3*ans << endl;
    }

    return 0;
}