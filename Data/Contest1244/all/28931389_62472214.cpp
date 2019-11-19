#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        int pos = -1;
        string data;
        cin >> data;
        for (int i = 0; i < n; ++i)
            if (data[i] == '1') {
                if ((pos == -1) || (max(pos, n - pos - 1) < max(i, n - i - 1)))
                    pos = i;
            }
        if (pos == -1)
            cout << n << "\n";
        else
            cout << 2 * max(pos, n - pos - 1) + 2 << "\n";
    }
}
