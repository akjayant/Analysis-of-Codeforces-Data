#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

//const int maxn = 100005;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
    int t;
    cin >> t;
    for(int ii = 0; ii < t; ++ii)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) cout << "Finite\n";
            else cout << "Infinite\n";
    }
    return 0;
}
