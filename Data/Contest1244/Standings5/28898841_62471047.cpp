#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, i;
    string s;
    for (i = 0; i < t; i ++)
    {
        cin >> n >> s;
        int cnt = 0, sz = s.size(), j, l = sz, r = 0;
        for (j = 0; j < sz; j ++)
        {
            if (s[j] == '1')
            {
                if (j < l)
                    l = j;
                r = j;
            }
        }
        l ++;
        r ++;
        if (l == sz + 1)
            cout << n << endl;
        else
        {
            int minl = r + max(sz - r + 1, r);
            int minr = (sz - l + 1) + max(l, sz - l + 1);
            cout << max(minl, minr) << endl;
        }
    }
    return 0;
}
