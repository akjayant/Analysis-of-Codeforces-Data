#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

const ll mod = 1e9 + 7;

ll mpow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll ans = mpow(a, b / 2, mod);
    ans = ans * ans % mod;
    if (b % 2 == 0)
        return ans;
    else
        return ans * a % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    ll i,n,a,b;
    cin >> a >> b;
    cout << mpow(mpow(2, b, mod) - 1, a, mod);
    return 0;
}
