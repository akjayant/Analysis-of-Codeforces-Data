#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1243"

int T, n;
int a[100005];
int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    for (cin >> T; T--;)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort (a + 1, a + 1 + n);
        int res = 0;
        for (int i = n; i > 0; i--)
            if (a[i] >= n - i + 1)
                res++;
            else
                break;
        cout << res << '\n';
    }
}
