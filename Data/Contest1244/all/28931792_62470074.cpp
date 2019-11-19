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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int fr = -1,lst = -1;
        loop(i,n)
        {
            if (s[i] == '1' && fr == -1)
            {
                fr = i;
                lst = i;
            } else if (s[i] == '1') lst = i;
        }
        if (lst == -1) cout << n << endl;
        else
        {
            //cout << lst << ' ' << fr << endl;
            cout << max((lst+1)*2,(n-fr) * 2) << endl;
        }
    }
}

