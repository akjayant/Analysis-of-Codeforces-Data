#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 100005
#define M 100005
#define INF 0x3f3f3f3f
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n; read(n);
        string s; cin >> s;
        int ans = n;
        int pre = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pre = i;
                break;
            }
        }
        if (pre != -1) {
            ans = max(ans, 2*(n - pre));
        }
        pre = -1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                pre = i;
                break;
            }
        }
        if (pre != -1) {
            ans = max(ans, 2*(pre+1));
        }
        cout << ans << endl;
    }
    return 0;
}
