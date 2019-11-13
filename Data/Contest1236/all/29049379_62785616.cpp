#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int main() {
    int _;
    cin >> _;
    while (_--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int x = min(c / 2, b);
        b -= x;
        int y = min(b / 2, a);
        cout << 3 * (x + y) << endl;
    }
    return 0;
}
