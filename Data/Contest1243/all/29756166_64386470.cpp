#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

const int maxa = 1e6 + 5;
int lp[maxa];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <ll> pr;
    for(int i = 2; i < maxa; ++i)
    {
        if (lp[i] == 0)
        {
            pr.pb(i);
            lp[i] = i;
        }
        for(int j = 0; j < int(pr.size()) && pr[j] * i < maxa && pr[j] <= lp[i]; ++j)
            lp[pr[j] * i] = pr[j];
    }
    ll n;
    cin >> n;
    for(int i = 0; i < int(pr.size()); ++i)
        if (n % pr[i] == 0)
    {
        while(n % pr[i] == 0)
            n /= pr[i];
        if (n == 1)
        {
            cout << pr[i];
        }
        else
        {
            cout << 1;
        }
        return 0;
    }
    cout << n;
    return 0;
}
