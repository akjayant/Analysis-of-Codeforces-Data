#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        ans = 3 * min(b, c / 2);
        b -= (ans) / 3;
        ans += 3 * min(a, b / 2);
        cout << ans << endl;
    }
    return 0;
}
