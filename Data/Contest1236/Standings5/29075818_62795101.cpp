#include <bits/stdc++.h>

using namespace std;

#define int long long
#define loop(i,n) for(int i = 0; i<n; ++i)
#define all(a) a.begin(),a.end()
#define FOR(i,n,m) for(int i = n; i<m; ++i)
#define rall(a) a.rbegin(),a.rend()

signed main()
{
    int t,m;
    cin >> t;
    vector <int> kavo(t*t);
    vector <vector <int> > ans(t);
    for (int i = 0; i<t*t; ++i)
    {
        //cout << i << ' ' << i/t << endl;
        if ((i/t)%2 == 0) ans[i%t].push_back(i);
        if ((i/t)%2 == 1) ans[t - 1 - (i%t)].push_back(i);
    }
    loop(i,t)
    {
        loop(j,t) cout << ans[i][j]+1 << ' ' ;
        cout << endl;
    }
}
