#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;



int main() {
    int test;
    cin >> test;
    while(test--) {
        int ans = 0, a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i <= a && i * 2 <= b; i++) {
            ans = max(ans, i + i * 2 + min(b - i - i, c / 2) * 3);
        }
        cout << ans << endl;
    }
    return 0;
}
