#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl;}

typedef long long LL;
const int N = 1E5 + 10;
const int base = 1E9 + 7;

int n;
char st[N];
int f[N];

void Solve() {
    bool flag = 1;
    int ans = 1;
    f[0] = 1; f[1] = 1;
    FOR(i, 2, n) f[i] = (f[i - 1] + f[i - 2]) % base;
    for (int i = 1; i <= n; i++) {
        int d = 0; //DEBUG(i);
        if (st[i] == 'u') {
            while (i <= n && st[i] == 'u') d++, i++;
            i--;
        } else if (st[i] == 'n') {
            while (i <= n && st[i] == 'n') d++, i++;
            i--;
        } else {
            if (st[i] == 'm') flag = 0;
            if (st[i] == 'w') flag = 0;
        }
       // DEBUG(d);
        ans = (LL)ans * f[d] % base;
    }
    printf("%d", ans * flag);
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // LOCAL
    scanf("%s", st + 1);
    n = strlen(st + 1);
    Solve();
    return 0;
}

