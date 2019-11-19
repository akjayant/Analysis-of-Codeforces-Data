#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

using ll = long long;
using namespace std;

ll M = 1000000007;
typedef pair<int, int> P;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n)
    {
        scanf("%d", &a[i]);
    }
    sort(all(a));
    ll small = 0, large = 0;

    rep(i, n / 2)
    {
        small += a[i];
    }
    FOR(i, n / 2, n)
    {
        large += a[i];
    }
    ll ans = small * small + large * large;
    printf("%lld\n", ans);
}