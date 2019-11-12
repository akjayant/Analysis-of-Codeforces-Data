#include<bits/stdc++.h>
#define lson sign << 1, l, mid
#define rson sign << 1 | 1, mid + 1, r
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f;
const long long inv2 = 500000004;
const int maxn = 1e5 + 5;

ll power(ll a, ll b, ll c) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = ans * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return ans % c;
}
char s[maxn], t[maxn];
int cnt[27];
int mp[27][27];
int main() {
    int n, T;
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        memset(mp, 0, sizeof(mp));
        scanf("%d", &n);
        scanf("%s %s", s + 1, t + 1);
        for(int i = 1; i <= n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
            if(s[i] == t[i])
                continue;
            mp[s[i] - 'a'][t[i] - 'a']++;
        }
        int flag = 1;
        for(int i = 0; i <= 25; i++) {
            if(cnt[i] & 1)
                flag = 0;
        }
        int num = 0;
        for(int i = 1; i <= n; i++) {
            if(mp[s[i] - 'a'][t[i] - 'a']) {
                if(mp[s[i] - 'a'][t[i] - 'a'] == 2)
                    num++;
                else
                    flag = 0;
            }
        }
        num/=2;
        if(num > 1)
            flag = 0;
        if(flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
