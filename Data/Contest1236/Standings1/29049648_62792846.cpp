#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;
typedef long long int lli;
typedef long double ld;

const int MOD = 1000000007;
lli binPow(lli num, lli p) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return num;
    }
    lli b = binPow(num, p / 2);
    b = (b * b) % MOD;
    if (p % 2 != 0) {
        b = (b * num) % MOD;
    }
    return b % MOD;
}

int main() {
    // ifstream cin("biconv.in");
    // ofstream cout("biconv.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    cout << binPow((binPow(2, m) + MOD - 1) % MOD, n);
}