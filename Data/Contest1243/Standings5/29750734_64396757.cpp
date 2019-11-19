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
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
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

int n, k, e;

void solve() {
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            k++;
            e = i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1) {
        k++;
        e = n;
    }
    if (k == 1) cout << e;
    else if (k > 1) cout << 1;
    else cout << n;
}
