#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;

        int sol = n;
        for (int i = 0; i < n; i++)
            if (str[i] == '1') {
                sol = max(sol, 2 * (i + 1));
                sol = max(sol, 2 * (n - i));
            }
        cout << sol << '\n';
    }
    return 0;
}
