#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

long long d[100000];
long long mod = 1000 * 1000 * 1000 + 7;

int main()
{
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    d[0] = d[1] = 1;
    int k = max(n, m);
    for (int i = 2; i <= k; ++i)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    long long ans1 = (d[n] + mod - 1) % mod;
    long long ans2 = (d[m] + mod - 1) % mod;
    long long ans = ((ans1 + ans2) % mod + 1) % mod;
    cout << (ans * 2) % mod;
    return 0;
}