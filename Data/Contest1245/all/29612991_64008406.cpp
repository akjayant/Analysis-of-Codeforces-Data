#include <bits/stdc++.h>

using namespace std;

#define ll long long


int up(int a, int b)
{
    if (a%b)
        return a/b + 1;
    return a/b;
}

int main()
{
    int q;
    cin >> q;
    for (int _i = 0; _i < q; ++_i)
    {
        int n, a, b, c;
        int r=0, p=0, s=0;
        cin >> n >> a >> b >> c;
        string seq;
        string ans;
        cin >> seq;
        for (int i=0; i<seq.size(); ++i)
        {
            ans.push_back('?');
            char t = seq[i];
            if (t=='R' && p < b)
                ++p, ans[i] = 'P';
            if (t=='P' && s < c)
                ++s, ans[i] = 'S';
            if (t=='S' && r < a)
                ++r, ans[i] = 'R';
        }
        if (r+p+s >= up(n, 2))
        {
            cout << "YES\n";
            for (int i=0; i<n; ++i)
            {
                char t = ans[i];
                if (t == '?')
                {
                    if (r < a)
                        ans[i] = 'R', ++r;
                    else if (p < b)
                        ans[i] = 'P', ++p;
                    else if (s < c)
                        ans[i] = 'S', ++s;
                }
            }
            cout << ans << "\n";
        }

        else
            cout << "NO\n";
    }

    return 0;
}









