#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 500 + 5;
int n, L[N], R[N], D[N];
char s[N];

int main() {
    scanf("%d%s", &n, s);
    int mi = n, cnt = 0;
    for(int k = 0; k < n; k++) {
        char chk = s[k];
        L[k + 1] = L[k];
        R[k + 1] = R[k];
        if(chk == '(') L[k + 1]++;
        else R[k + 1]++;
        D[k + 1] = L[k + 1] - R[k + 1];
        if(D[k + 1] < mi) {
            mi = D[k + 1];
            cnt = 1;
        } else if(D[k + 1] == mi) cnt++;
    }
    int ans = 0, l = 1, r = 1;
    if(L[n] != R[n]) {
        puts("0");
        puts("1 1");
        return 0;
    }
    if(cnt > ans) ans = cnt;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            char chi = s[i];
            char chj = s[j];
            if(chi == chj) continue;
            L[0] = 0; R[0] = 0;
            mi = n; cnt = 0;
            for(int k = 0; k < n; k++) {
                char chk = s[k];
                if(k == i || k == j) {
                    if(chk == '(') chk = ')';
                    else chk = '(';
                }
                L[k + 1] = L[k];
                R[k + 1] = R[k];
                if(chk == '(') L[k + 1]++;
                else R[k + 1]++;
                D[k + 1] = L[k + 1] - R[k + 1];
                if(D[k + 1] < mi) {
                    mi = D[k + 1];
                    cnt = 1;
                } else if(D[k + 1] == mi) cnt++;
            }
            if(cnt > ans) {
                ans = cnt;
                l = i + 1; r = j + 1;
            }
        }
    }
    printf("%d\n%d %d\n", ans, l, r);
    return 0;
}

