#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    for (long long tt = 0; tt < t; tt++)
    {
        long long n, m;
        cin >> n;
        long long cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x; if (x % 2 == 0) cnt2++; else cnt1++;
        }
        cin >> m;
        for (long long i = 0; i < m; i++)
        {
            long long x;
            cin >> x; if (x % 2 == 0) cnt4++; else cnt3++;
        }
        long long ans = cnt1*cnt3+cnt2*cnt4;
        cout << ans << endl;
    }
    return 0;
}
