#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<int> arr[305];

void solve() {
    int n; scanf("%d", &n);
    bool flip = true;
    for (int i = 0; i < n*n; i++) {
        if (i%n == 0) flip = !flip;
        if (flip) arr[n-(i%n)-1].push_back(i);
        else arr[i%n].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]+1);
        }
        printf("\n");
    }
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
