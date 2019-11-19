#include <bits/stdc++.h>

#define int long long
#define loop(i,n) for(int i = 0; i<n; ++i)
#define all(a) a.begin(),a.end()
#define FOR(i,n,m) for(int i = n; i<m; ++i)
#define rall(a) a.rbegin(),a.rend()

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d,k,fl = 0;
        int ans1,ans2;
        cin >> a >> b >> c >> d >> k;
        for(int i = 0; i<=100; ++i)
            for(int j = 0; j<=100; ++j)
        if (i*c >= a && j*d >= b && i+j<= k && fl == 0) {
                cout << i << ' ' << j << endl;
                fl = 1;
        }
        if (fl == 0) cout << -1 << endl;
    }
}

