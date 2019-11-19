#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;

int n;
map<int, int> m;
vector<int> res;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    int nt = 2;
    while(n > 1 && nt * nt <= n)
    {
        if(n % nt == 0) res.pb(nt);
        while(n % nt == 0 && n > 1)
        {
            n = n / nt;
        }
        nt += 1;
    }
    if(n > 1) res.pb(n);
    if(res.size() > 1)
    {
        cout << 1;
    }
    else
    {
        cout << res.back();
    }


}

/**
TEST:


*/
