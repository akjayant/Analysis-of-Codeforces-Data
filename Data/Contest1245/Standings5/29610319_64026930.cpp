#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

char s[100005];
int f[100005];

void Solve() {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        f[0] = 1;
        for(int i = 1; i <= n; ++ i) {
            f[i] = f[i-1];
            if(s[i] == 'u' && s[i-1] == 'u')
                f[i] = (f[i] + f[i-2]) % mod;
            if(s[i] == 'n' && s[i-1] == 'n')
                f[i] = (f[i] + f[i-2]) % mod;
            if(s[i] == 'm' || s[i] == 'w') {puts("0"); return;}
        }
        printf("%d", f[n]);
}

#define task "main"
int main() {
        //freopen(task".inp","r",stdin);
        //freopen(task".out","w",stdout);
        Solve();
}
