#include<bits/stdc++.h>
using namespace std;



int main()
{
    int T;
    cin >> T;
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int t1 = c/2;
        t1 = min(t1, b);
        int ans = 0;
        ans += t1 * 3;
        b -= t1;
        int t2 = b/2;
        t2 = min(t2, a);
        ans += t2 * 3;
        cout << ans << endl;
    }
}