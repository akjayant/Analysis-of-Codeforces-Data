#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>

using namespace std;

long long gcd(long long a, long long b) {
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int dp[101][101][101];

int main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (i >= 1 && j >= 2)
                    dp[i][j][k] = dp[i - 1][j - 2][k] + 3;
                if (j >= 1 && k >= 2)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 2] + 3);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << dp[a][b][c] << endl;
    }
}
