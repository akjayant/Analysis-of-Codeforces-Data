#include <bits/stdc++.h>
#define N ((int)1e6+10)
#define MD ((int)1e9+7)

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b>>c;
        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int aa = i;
                int bb = i * 2 + j;
                int cc = j * 2;
                if (aa > a || bb > b || cc > c)
                    continue;
                ans = max(ans, aa + bb + cc);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
