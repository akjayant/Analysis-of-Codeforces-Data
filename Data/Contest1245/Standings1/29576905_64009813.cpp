#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 100010, p = 1e9+7;

int fib[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    cin >> s;
    int n = strlen(s);
    for(int i = 0; i < n; ++i){
        if (s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
    }
    fib[0] = fib[1] = 1;
    rep(i, 2, n) (fib[i] = fib[i-1] + fib[i-2]) %= p;
    int cnt = 0;
    ll ans = 1;
    for(int i = 0; i <= n; ++i){
        if (s[i] == s[i-1]){
            if (s[i] == 'n' || s[i] == 'u') cnt++;
        } else {
            (ans *= fib[cnt]) %= p;
            if (s[i] == 'n' || s[i] == 'u') cnt = 1;
            else cnt = 0;
        }
    }
    cout << ans;
    return 0;
}
