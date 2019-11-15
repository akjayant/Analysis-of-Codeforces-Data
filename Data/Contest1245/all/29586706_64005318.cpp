#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int t, a[3], n, p[maxn], r[maxn], s;
char ch[maxn];
const char tr[4] = {'0', 'R', 'S', 'P'};

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a[0] >> a[2] >> a[1];
        scanf("%s", ch);
        s = 0;
        inc(i, 0, n - 1) {
            r[i] = 0;
            inc(j, 1, 3) if (tr[j] == ch[i]) {
                int nxt = (j % 3 + 1) % 3;
                if (a[nxt] > 0) {
                    a[nxt]--, s++;
                    r[i] = nxt + 1;
                }
            }
        }
        if (s * 2 >= n) {
            puts("YES");
            inc(i, 0, n - 1) {
                if (r[i] == 0) {
                    inc(j, 0, 2) {
                        if (a[j] > 0) {
                            a[j]--;
                            r[i] = j + 1;
                            break;
                        }
                    }
                }
                cout << tr[r[i]];
            }
            printf("\n");
        } else
            puts("NO");
    }
}
