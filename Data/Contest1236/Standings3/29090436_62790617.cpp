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

long long mod = 1000000007;

long long bin_pow(long long n, long long k) {
    long long ret = 1;
    while (k) {
        if (k & 1)
            ret = (ret * n) % mod;
        n = (n * n) % mod;
        k /= 2;
    }
    return ret;
}

int main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
    long long n, m;
    cin >> n >> m;
    long long ans = bin_pow(2, m) - 1;
    cout << bin_pow(ans, n);
}
