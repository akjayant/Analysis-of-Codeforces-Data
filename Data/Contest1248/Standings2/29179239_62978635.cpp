#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long no1 = 0;
        long long yes1 = 0;
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0) no1++;
            else yes1++;
        }
        int m;
        cin >> m;
        long long no2 = 0;
        long long yes2 = 0;
        for (long long i = 0; i < m; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0) no2++;
            else yes2++;
        }
        cout << no1 * no2 + yes1 * yes2 << '\n';
    }
    return 0;
}
