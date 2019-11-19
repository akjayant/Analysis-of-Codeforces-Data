#include <iostream>

using namespace std;

int main()
{
    int t, i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int f = n, l = 0;
        for (j = 0; j < n; j++) {
            if (a[j] == '1') {
                f = min (f, j);
                l = max(l, j);
            }
        }
        if (f == n) {
            cout << n << endl;
            continue;
        }
        cout << max(max(f + 1, n - f), max(n - l, l + 1)) * 2 << endl;
    }
}
