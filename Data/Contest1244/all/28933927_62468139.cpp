#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define f first
#define s second

const int MAXN = 1e6 + 3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int z, n;
    int wyn, x, y;
    string s;
    cin >> z;
    while (z--) {
        cin >> n >> s;
        wyn = n;
        x = n + 1;
        y = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                x = min(x, i);
                y = max(y, i);
            }
        }
        wyn = max(wyn, 2 * (n - x));
        wyn = max(wyn, 2 * (y + 1));
        cout << wyn << '\n';
    }
    return 0;
}

