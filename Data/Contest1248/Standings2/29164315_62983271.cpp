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

    int n;
    cin >> n;
    long long sol = 0ll;
    long long x = 0ll;
    long long y = 0ll;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            x += arr[i];
        }
        else
        {
            y += arr[i];
        }
    }
    sol = x * x + y * y;
    cout << sol;
    return 0;
}