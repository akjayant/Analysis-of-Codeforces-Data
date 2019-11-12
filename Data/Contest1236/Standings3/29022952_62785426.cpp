#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int _min = min(b, c / 2);
        int ans = min(b, c / 2) * 3;
        b -= _min;
        ans += min(a, max(0, b / 2)) * 3;
        cout << ans << endl;
    }
}
