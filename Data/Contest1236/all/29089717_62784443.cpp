#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, x) for(int i = 0; i < x; i++)
#define rforn(i, x) for(int i = x - 1; i >= 0; i--)

using namespace std;

template<typename T> void print(T a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans1 = min(b, c / 2);
    b -= ans1;
    c -= ans1 * 2;
    
    int ans2 = min(a, b / 2);
    b -= ans2;
    c -= ans2 * 2;
    
    cout << (ans1 + ans2) * 3 << endl;
}

signed main()
{
    int t;
    cin >> t;
    forn (i, t)
        solve();
    return 0;
}