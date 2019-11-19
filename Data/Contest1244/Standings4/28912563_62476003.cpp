#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <bitset>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>

using namespace std;
using namespace __gnu_pbds;



void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#define int long long

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

#define int long long

int n, p, w, d, cur;

void solve() {
    cin >> n >> p >> w >> d;
    if (w > d) {
        for (int i = 0; i <= w; i++) {
            cur = i * d;
            if (p - cur >= 0 && (p - cur) % w == 0 && cur / d + (p - cur) / w <= n) {
                cout << (p - cur) / w << " " << cur / d << " " << n - cur / d - (p - cur) / w;
                exit(0);
            }
        }
    } else {
        for (int i = 0; i <= d; i++) {
            cur = i * w;
            if (p - cur >= 0 && (p - cur) % d == 0 && cur / w + (p - cur) / d <= n) {
                cout << (p - cur) / d << " " << cur / w << " " << n - cur / w - (p - cur) / d;
                exit(0);
            }
        }
    }
    cout << -1;
}
