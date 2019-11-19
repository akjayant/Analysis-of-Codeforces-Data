#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ans = max(ans, 2 * (i + 1));
                ans = max(ans, n + 1);
                ans = max(ans, 2 * (n - 1 - i + 1));
            }
        }
        cout << ans << "\n";
    }


    return 0;
}
