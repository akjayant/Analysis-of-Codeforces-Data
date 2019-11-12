#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;

        int _a = a;
        int _b = b;
        int _c = c;

        int ans = 0;
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                a = _a;
                b = _b;
                c = _c;

                int res = 0;

                res += i * 3;
                a -= i;
                b -= i * 2;

                b -= j;
                c -= j * 2;

                res += j * 3;

                if (a > -1 && b > -1 && c > -1) {
                    ans = max(ans, res);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
/*
*/
