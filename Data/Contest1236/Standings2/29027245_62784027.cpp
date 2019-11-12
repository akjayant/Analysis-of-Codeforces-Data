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

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    int tmp = min(c/2, b);
    b-= tmp;
    ans += 3*tmp;
    ans += 3*min(b/2, a);
    printf("%d\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        solve();
    }
}
