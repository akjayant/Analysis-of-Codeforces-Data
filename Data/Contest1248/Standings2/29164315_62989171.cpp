/*
Author: Sagar Gupta
E mail: sagar.june97p@gmail.com
*/

#pragma comment(linker, "/STACK:268435456")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl ("\n")
#define deb(n) cerr << #n << " = " << (n) << '\n'
#define FOR(i, n) for (int(i) = 0; (i) < n; (i)++)
#define PI (3.141592653589)
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef pair<int, int> pp;
#define MOD 1000000007
int f[(1 << 20)];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    // Those who cannot acknowledge themselves, will invariably fail

    long long n, m;
    cin >> n >> m;
    const int s = 100001;
    long long arr[s];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < s; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] %= MOD;
    }
    cout << ((2 * arr[n] + 2 * arr[m]) % MOD - 2 + MOD) % MOD;
    return 0;
}