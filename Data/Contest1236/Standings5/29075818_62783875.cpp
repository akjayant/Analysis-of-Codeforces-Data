#include <bits/stdc++.h>

using namespace std;

#define int long long
#define loop(i,n) for(int i = 0; i<n; ++i)
#define all(a) a.begin(),a.end()
#define FOR(i,n,m) for(int i = n; i<m; ++i)
#define rall(a) a.rbegin(),a.rend()

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,ans = 0;
        cin >> a >> b >> c;
        while (c >= 2 && b >= 1)
        {
            ans += 3;
            c-=2;
            b-=1;
        }
        while (a >= 1 && b >= 2)
        {
            ans += 3;
            b-=2;
            a-=1;
        }
        cout << ans << endl;
    }
    //system("pause");
}
