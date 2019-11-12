#include <bits/stdc++.h>
using namespace std;

int a[1005], q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);

        int rez = 0;

        for (int i = n; i >= 1; i--)
            rez = max(rez, min((n - i + 1), a[i]));
        cout << rez << "\n";
    }


    return 0;
}