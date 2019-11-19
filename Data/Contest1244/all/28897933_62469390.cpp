#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int t;
int n;
string a;

main () {
    cin >> t;

    for (int i = 1; i <= t; i ++) {
        cin >> n;
        cin >> a;

        int l = 0,r = 0;

        for (int j = 0; j < n; j ++) {
            if (a[j] == '1' && !l) {
                l = j + 1;
            }
            if (a[j] == '1') r = j + 1;
        }
        if (l == 0) cout << n << endl;
        else {
            int ans = n;
            ans = max(ans,l * 2);
            ans = max(ans,n + 1);
            ans = max(ans,(n - l + 1) * 2);

            ans = max(ans,r * 2);
            ans = max(ans,n + 1);
            ans = max(ans,(n - r + 1) * 2);
            cout << ans << endl;
        }
    }
}
