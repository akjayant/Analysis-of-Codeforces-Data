#include<bits/stdc++.h>
 
using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;
 
int main() {
    cout.precision(20);
    cout << fixed;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = min(c / 2, b);
        b -= ans;
        ans += min(a, b / 2);
        cout << 3 * ans << endl;
    }
    return 0;
}