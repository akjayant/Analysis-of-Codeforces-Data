#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n, r, p, s;
        string bb;
        cin >> n >> r >> p >> s >> bb;

        int w = 0;
        string ans;
        for (int i = 0; i < n; i++)
            if (bb[i] == 'R')
                if (p)
                    ans += 'P', p--, w++;
                else
                    ans += '-';
            else if (bb[i] == 'P')
                if (s)
                    ans += 'S', s--, w++;
                else
                    ans += '-';
            else
                if (r)
                    ans += 'R', r--, w++;
                else
                    ans += '-';

        if (w * 2 >= n)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                if (ans[i] == '-')
                {
                    if (p)
                        cout << 'P', p--;
                    else if (s)
                        cout << 'S', s--;
                    else
                        cout << 'R', r--;
                }
                else
                    cout << ans[i];
            cout << '\n';
        }
        else
            cout << "NO\n";
    }


    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***
//     *****  *****  *****
//    *      *   *  *
//   *      *****  *
//  *      *  *   *
//  ***** *   *   *****
