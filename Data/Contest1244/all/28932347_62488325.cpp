#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000010;
const long long MAXINT = 9223372036854775807;

long long c[MAXN][4];

int n;
int neighbors[MAXN][3];
int deg[MAXN];
int b[MAXN];
int best[MAXN];
long long ans = MAXINT;

void InitTree() {
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
    }
}

void Try(int x, int p, int c0, int c1, int c2) {
    int cnt = 0;
    long long sum = 0;
    while (true) {
        // cout << sum << ": Looking ..." << x << " p = " << p << endl;
        int next = -1;
        if (cnt % 3 == 0) {
            b[x] = c0;
        } else if (cnt % 3 == 1) {
            b[x] = c1;
        } else {
            b[x] = c2;
        }
        cnt += 1;
        sum += c[x][b[x]];
        for (int j = 0; j < deg[x]; j++) {
            int y = neighbors[x][j];
            if (y != p) {
                next = y;
            }
        }
        if (next == -1) {
            // cout << sum << ": Ans of " << c0 << c1 << c2 << endl;
            if (sum < ans) {
                for (int i = 1; i <= n; i++) {
                    best[i] = b[i];
                }
                ans = sum;
            }
            return;
        }
        p = x;
        x = next;
    }
}

bool AddEdge(int x, int y) {
    if (deg[x] == 2 || deg[y] == 2) {
        return false;
    }
    neighbors[x][deg[x]] = y;
    neighbors[y][deg[y]] = x;
    deg[x] += 1;
    deg[y] += 1;
    return true;
}

int main() {
    cin >> n;
    for (int j = 1; j < 4; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> c[i][j];
        }
    }
    InitTree();
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        if (!AddEdge(x, y)) {
            cout << -1 << endl;
            return 0;
        }
    }
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            start = i;
            break;
        }
    }
    int p = -1;
    int x = start;
    Try(x, p, 1, 2, 3);
    Try(x, p, 1, 3, 2);
    Try(x, p, 2, 3, 1);
    Try(x, p, 2, 1, 3);
    Try(x, p, 3, 1, 2);
    Try(x, p, 3, 2, 1);
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << best[i] << " ";
    }
    cout << endl;
    return 0;
}
