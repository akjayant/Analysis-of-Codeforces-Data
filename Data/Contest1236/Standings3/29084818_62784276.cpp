#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int result = min(c/2, b);
        b -= result;
        result += min(b/2, a);
        cout << 3 * result << '\n';
    }
    return 0;
}
