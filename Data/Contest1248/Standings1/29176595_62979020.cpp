#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;

const int N = 300707;
int n;
int a, b;

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
    for (int k = 1; k <= t; k++){
        int n, m;
        cin >> n;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x % 2 == 0){
                c2++;
            }
            else {
                c1++;
            }
        }
        cin >> m;
        int b1 = 0, b2 = 0;
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            if (x % 2 == 0){
                b2++;
            }
            else {
                b1++;
            }
        }
        cout << b1 * c1 + b2 * c2 << endl;
    }

    return 0;
}
