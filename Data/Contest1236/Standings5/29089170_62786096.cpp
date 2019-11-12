#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;

    for (int _ = 0; _ < t; ++_) {
        int a, b, c;
        cin >> a >> b >> c;
        int res = min(c / 2, b) * 3;
        b -= min(b, c / 2);
        res += min(a, b / 2) * 3;
        cout << res << endl;
    }

    return 0;
}