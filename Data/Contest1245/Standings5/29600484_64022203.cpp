#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

//#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int N = 1000000;
int a, b, t;
int dd[N];

void solve()
{
    cin >> a >> b;
    int ucln = __gcd(a, b);
    if(ucln == 1) cout << "Finite" << '\n';
    else cout << "Infinite" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

}

/**
    Code by: Best_Nakroth 12TH.


*/
