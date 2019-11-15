#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<int> arr;

int powMod(int x, int y) {
    //printf("calc %d %d\n", x, y);
    if (y == 0) return 1;
    ll ret = powMod(x, y/2);
    ret = (ret*ret)%MOD;
    if (y%2) ret = (ret*x)%MOD;
    return ret;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    printf("%d\n", powMod((powMod(2, m)-1+MOD)%MOD, n));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        solve();
    }
}
