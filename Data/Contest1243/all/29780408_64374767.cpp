#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans=0;
        cin >> n;
        vector <int> a(n);
        for (int i=0; i<n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (int i=0; i<n; ++i)
        {
            if (a[i] >= i+1)
                ans = max(ans, i+1);
            else
                ans = max(ans, a[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}









