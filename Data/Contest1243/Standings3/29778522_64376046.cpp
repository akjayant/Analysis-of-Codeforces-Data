#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("file.in", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        bool fl = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < n - i) {
                cout << n - i - 1;
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << n;
        cout << "\n";
    }
}
