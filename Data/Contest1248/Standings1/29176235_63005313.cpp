#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int mx = 0, l = 1, r = 1;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            string t = s;
            swap(t[i], t[j]);

            int val[500] = {};
            val[0] = (t[0] == '(' ? 1 : -1);
            for (int k = 1; k < n; k++)
                val[k] = val[k - 1] + (t[k] == '(' ? 1 : -1);

            if (val[n - 1])
                continue;

            int mn = 0;
            for (int k = 0; k < n; k++)
                mn = min(mn, val[k]);

            int cnt = 0;
            for (int k = 0; k < n; k++)
                cnt += (val[k] == mn);

            if (cnt > mx)
                mx = cnt, l = i + 1, r = j + 1;
        }
    cout << mx << '\n' << l << ' ' << r << '\n';

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
