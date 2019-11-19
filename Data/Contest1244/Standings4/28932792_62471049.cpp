#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int ms = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a; string s;
        cin >> a;
        cin >> s;
        int l = -1, r = -2;
        for (int i = 0; i < a; ++i)
        {
            if (s[i] == '1')
            {
                l = i;
                break;
            }
        }
        if (l == -1)
        {
            cout << a << "\n"; continue;
        }
        r = l;
        for (int i = a - 1; i > l; --i)
        {
            if (s[i] == '1')
            {
                r = i;
                break;
            }
        }
        int res = (r - l + 1) * 2;
        r = a - r - 1;
        res += max(l + r, max(2 * l, 2 * r));
        cout << res << "\n";
    }
    return 0;
}
