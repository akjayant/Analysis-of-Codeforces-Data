#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;
ll OO = (ll) 1e18 ;
int Mod = 1e9 + 7;
ll const N = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int c1 = min(c / 2, b);
        b -= c1;
        c1 += min(b / 2, a);
        cout << c1 * 3 << endl;
    }
}
