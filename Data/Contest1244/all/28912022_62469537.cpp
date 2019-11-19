#include <bits/stdc++.h>
using namespace std;
char a[1005];
int main ()
{
    ios::sync_with_stdio(false);
    int T;cin >> T;
    while (T--)
    {
        int n;cin >> n >> a;
        int le = -1,ri = -1;
        for (int i = 0;i < n;i++)
            if (a[i] == '1') {le = i;break;}
        for (int i = n - 1;i >= 0;--i)
            if (a[i] == '1') {ri = i;break;}
        if (le == -1) cout << n << endl;
        else if (le == ri)
            cout << max((n - ri) * 2,(le + 1) * 2) << endl;
        else cout << (ri - le + 1) * 2 + 2 * max(le,n - ri - 1) << endl;
    }
    return 0;
}