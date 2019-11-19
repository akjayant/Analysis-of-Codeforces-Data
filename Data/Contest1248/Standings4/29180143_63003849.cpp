#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define endl '\n'
// #define Local
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    a[1] = a[2] = 2;
    for (int i = 3; i < maxn; ++i) a[i] = (a[i - 1] + a[i - 2]) % mod;
    for (int i = 1; i < maxn; ++i) a[i] = (a[i] + a[i - 1]) % mod;
    int n, m; cin >> n >> m;
    cout << (2 + a[n - 1] + a[m - 1]) % mod << endl;
}