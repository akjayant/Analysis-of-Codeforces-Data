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

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i != 0)
            continue;

        while (n % i == 0) {
            n /= i;
        }

        if (n == 1) {
            cout << i;
        }
        else {
            cout << 1; 
        }
        return 0;
    }

    cout << ans;
    return 0;
}
