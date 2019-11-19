#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;
const int N = 100777;
char a[N];
int n;

signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    int t;

    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> n;
        int l = 0, r = 0;
        int col = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] == '1'){
                col++;
                if (l == 0){
                    l = i;
                }
                r = i;
            }
        }
        int ans = n;
        if (col > 0)
            ans = max(ans, max(2 * r, 2 * (n - l + 1)));
        if (col > 0)
            ans = max(ans, l - 1 + (n - r) + 2 * col + r - l + 1 - col);
        cout << ans << endl;
    }

    return 0;
}
