#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int n;
char ch[maxn];

int work() {
    int minrec = n, minpos, cnt = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
        if (ch[i] == '(') cnt ++;
        else cnt --;
        if (minrec > cnt && ch[i] == '(') minrec = cnt, minpos = i;
    }
    cnt = 0;
    for (int i = 1, j = minpos; i <= n; ++i, j = j == n ? 1 : j + 1) {
        if (ch[j] == '(') cnt ++;
        else {
            cnt --;
            if (cnt == 0) res ++;
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    scanf("%s", ch + 1);
    int pd = 0;
    for (int i = 1; i <= n; ++i) pd += ch[i] == '(' ? 1 : -1;
    if (pd) { puts("0\n1 1"); return 0; }
    int ans = work(), ansl = 1, ansr = 1;
    //printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            swap(ch[i], ch[j]);
            int tmp = work();
            if (tmp > ans) { ans = tmp, ansl = i, ansr = j; }
            swap(ch[i], ch[j]);
        }
    }
    printf("%d\n%d %d", ans, ansl, ansr);
    return 0;
}