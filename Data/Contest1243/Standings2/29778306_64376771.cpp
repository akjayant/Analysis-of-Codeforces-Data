#include <bits/stdc++.h>
using namespace std;

#define maxn 1010

int ntest, n;
int a[maxn];
int res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, min(a[i], n - i + 1));
        cout << res << endl;
    }
    return 0;
}
