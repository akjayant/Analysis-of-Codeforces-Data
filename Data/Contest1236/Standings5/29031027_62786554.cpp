#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <cmath>

#define pii pair<int, int>
#define all(a) a.begin(),a.end()
#define y1 erd
#define int long long

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;

using namespace std;

int tt;
int32_t main()
{
    cin >> tt;
    while(tt--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int k1 = min(a, b / 2);
        ans += 3 * k1;
        k1 = min(b - 2 * k1, c / 2);
        ans += 3 * k1;
        int res = 0;
        int k2 = min(b, c / 2);
        res = 3 * k2;
        k2 = min(a, (b - k2) / 2);
        res += 3 * k2;
        cout << max(ans, res) << endl;
    }


}
