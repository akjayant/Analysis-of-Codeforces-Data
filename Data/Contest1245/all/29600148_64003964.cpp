#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl;}

const int N = 105;

int n, R, P, S;
char st[N];

void Solve() {
    int d[256] = {0};
    char ans[105];
    FOR(i, 1, n) d[st[i]]++;
    int win = min(d['R'], P) + min(d['P'], S) + min(d['S'], R);
    FOR(i, 1, n) ans[i] = '-';
    if (win >= (n + 1) / 2) {
        puts("YES");
        FOR(i, 1, n) {
            if (st[i] == 'R' && P > 0) ans[i] = 'P', P--;
            if (st[i] == 'P' && S > 0) ans[i] = 'S', S--;
            if (st[i] == 'S' && R > 0) ans[i] = 'R', R--;
        }
        FOR(i, 1, n) if (ans[i] == '-') {
            if (R > 0) ans[i] = 'R', R--;
                else if (P > 0) ans[i] = 'P', P--;
                    else ans[i] = 'S', S--;
        }
        FOR(i, 1, n) putchar(ans[i]);
        putchar('\n');
    } else puts("NO");
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        scanf("%d%d%d", &R, &P, &S);
        scanf(" %s", st + 1);
        Solve();
    }
    return 0;
}
