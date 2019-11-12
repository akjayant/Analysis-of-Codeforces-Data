#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    int a,b,c;
    while(t--)
    {
        int ans = 0;
        cin >> a >> b >> c;
        int mi = min(b,c/2);
        ans += 3 * mi;
        b -= mi;
        mi = min(a,b/2);
        ans += 3 * mi;
        cout << ans << endl;
    }
    return 0;
}