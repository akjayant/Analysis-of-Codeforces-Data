#define mm(a) memset(a,0,sizeof(a));
#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) (x)<(y)?(x):(y)
#define Fopen freopen("1.in","r",stdin); freopen("m.out","w",stdout);
#define rep(i, a, b) for(int i=(a);i<=(b);i++)
#define per(i, b, a) for(int i=(b);i>=(a);i--)
#define PII pair<ll,ll>

#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 5;
const ll mod = 1e9 + 7;


int n, pre[MAXN];
char s[MAXN];

bool can() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)if (s[i] == '(')cnt++;
    return cnt == (n - cnt);
}


int ck() {
    int ans = 0;
    int minn = 0;
    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1), minn = min(minn, pre[i]);
    int st = 0;
//    for (int i = 1; i <= n; i++)printf("%d%c", pre[i], i == n ? '\n' : ' ');
    for (int i = 1; i <= n; i++) {
        if (pre[i] == minn) {
            st = i;
            break;
        }
    }
    int pos = st;
    int cnt = 0;
    int now = 0;
    if (pos == n)pos = 1;
    else pos++;
    while (pos != st) {
        if (s[pos] == '(')now++;
        else now--;
        if (now == 0)cnt++;
        if (pos == n)pos = 1;
        else pos++;
    }
//    printf("%s %d %d\n", s + 1, st % n + 1, cnt);
    return cnt + 1;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (!can())return printf("0\n1 1\n"), 0;
    int ans = 0, l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            swap(s[i], s[j]);
            int now = ck();
//            printf("%d %d %d\n", i, j, now);
            if (now > ans) {
                ans = now;
                l = i;
                r = j;
            }
            swap(s[i], s[j]);
        }
    }
    printf("%d\n", ans);
    printf("%d %d\n", l, r);
    return 0;
}
/*
 4
 (())
 */