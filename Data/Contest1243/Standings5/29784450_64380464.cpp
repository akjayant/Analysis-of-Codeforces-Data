#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if ((n - i) >= a[i])
            {
                s = max(s, a[i]);
            }
            else
            {
                s = max(s, n - i);
            }
        }
        cout << s << endl;
    }
    return 0;
}