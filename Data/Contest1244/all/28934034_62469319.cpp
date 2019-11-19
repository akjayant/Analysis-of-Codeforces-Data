#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
using namespace std;
int q, n;
string s;
int32_t main()
{   //srand(chrono::steady_clock::now().time_since_epoch().count());
    boost;
    cin >> q;
    while(q--) {
        cin >> n >> s;
        int res = 0;
        for(auto i : s) {
            if(i == '0')
                res++;
            else if(i == '1')
                res += 2;
        }
        for(int i = 1; i <= n; i++) {
            if(s[i - 1] == '1') {
                res = max(res, 2 * i);
                res = max(res, (n - i + 1) * 2);
            }
        }
        cout << res << "\n";
    }
}
