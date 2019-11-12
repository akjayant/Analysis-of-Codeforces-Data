#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

ll a[1010];

int main()
{
  //  freopen("input.txt", "r", stdin);

    ll n, i, j, k, x, y, z, cs, ts;

    sl(ts);

    while(ts--)
    {
        sl(n);
        for (i = 1; i <= n; i++)
            sl(a[i]);

        ll ans = 0;

        sort(a+1, a+n+1, greater<ll>());

        for (i = 1; i <= n; i++)
        {
            if (i >= a[i])
                ans = max(a[i], ans);
            else
                ans = max(i, ans);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
