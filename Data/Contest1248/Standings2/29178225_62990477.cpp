/* GCC */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>

#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))

using namespace std;

int mod = 1e9 + 7;
int n, m, i, j, k, a[100010];

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    a[0] = 1;
    a[1] = 1;
    for(i = 2; i <= 1e5; i++)
        a[i] = (a[i - 1] + a[i - 2]) % mod;

    cin >> n >> m;
    cout << (((a[n] + a[m] - 1) % mod) * 2) % mod;

    return 0;
}











