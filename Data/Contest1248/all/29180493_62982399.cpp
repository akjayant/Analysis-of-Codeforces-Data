#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100033;
ll a[MAXN];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (n & 1)
    {
        ll X = 0, Y = 0, ans = 0;
        for (int i = 1; i <= n; i++)
            Y += a[i];
        for (int i = 1; i <= n / 2; i++)
            X += a[i];
        Y -= X;
        ans = max(ans, X * X + Y * Y);
        X += a[n / 2 + 1];
        Y -= a[n / 2 + 1];
        ans = max(ans, X * X + Y * Y);
        cout << ans;
    }
    else
    {
        ll X = 0, Y = 0;
        for (int i = 1; i <= n; i++)
            Y += a[i];
        for (int i = 1; i <= n / 2; i++)
            X += a[i];
        Y -= X;
        cout << X * X + Y * Y;
    }
    cout.flush();
    // system("pause");

    return 0;
}