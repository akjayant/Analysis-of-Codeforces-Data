#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int qq = 0; qq < t; qq++)
    {
        int n, f = 1001, l = -1;
        string s;
        cin >> n >> s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                f = min(i, f);
                l = max(i, l);
            }
        }

        if(f == 1001 && l == -1)
            cout << n << '\n';
        else
            cout << max((l + 1) * 2, (n - f) * 2) << '\n';
    }
    return 0;
}
