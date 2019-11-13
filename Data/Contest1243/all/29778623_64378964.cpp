#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 10;

void yn(int x) {
    if (x) cout << "Yes" << endl;
    else cout << "No" << endl;
}


char a[maxn];
char b[maxn];

int main() {

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cin >> a + 1 >> b + 1;
        int i = -1, j = -1, l = -1;
        for (int k = 1; k <= n; k++) {
            if (a[k] == b[k]) continue;
            if (i == -1) {
                i = k;
            } else if (j == -1) {
                j = k;
            } else {
                l = 1;
                break;
            }
        }
        if (l == 1 || (i != -1 && j == -1)) {
            cout << "No" << endl;
        } else {
            if (i == -1 && j == -1)
                cout << "Yes" << endl;
            else if (a[i] == a[j] && b[i] == b[j])
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }


    return 0;
}