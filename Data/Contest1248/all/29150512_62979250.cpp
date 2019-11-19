#include <bits/stdc++.h>

using namespace std;

int T;

long long SolveTest () {
    long long n, m, x;
    long long odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;

    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> x;

        if (x % 2 == 0) ++ even1;
        else ++ odd1;
    }

    cin >> m;
    for (int i = 1; i <= m; ++ i) {
        cin >> x;
        if (x % 2 == 0) ++ even2;
        else ++ odd2;
    }

    long long ans = even1 * even2 + odd1 * odd2;
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> T;
    while (T--) {
        cout << SolveTest () << '\n';
    }

    return 0;
}
