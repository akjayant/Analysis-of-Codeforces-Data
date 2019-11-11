#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5+10;
const int mod = 1e9+7;

char str[maxn];
int f[maxn];

int main() {
    f[0] = 1;
    scanf("%s", str+1);
    for (int i = 1; i < maxn; ++i) f[i] = (f[i-1] + f[i-2])%mod;
    ll ans = 1;
    for (int i = 1; str[i];) {
        if(str[i] == 'u' || str[i] == 'n') {
            int l = i;
            while (str[i] && str[i] == str[l]) ++i;
            ans = ans * f[i - l] % mod;
        } else if(str[i] == 'm' || str[i] == 'w'){
            ans = 0;
            break;
        } else {
            ++i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}