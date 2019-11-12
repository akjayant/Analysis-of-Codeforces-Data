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
vector<pair<int, int> >ans;
int main() {
    int n, T;
    scanf("%d", &T);
    while(T--) {
        ans.clear();
        memset(cnt, 0, sizeof(cnt));
        memset(mp, 0, sizeof(mp));
        scanf("%d", &n);
        scanf("%s %s", s + 1, t + 1);
        for(int i = 1; i <= n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
        int flag = 1;
        for(int i = 0; i <= 25; i++) {
            if(cnt[i] & 1)
                flag = 0;
        }
        for(int i = 1; i <= n && flag; i++) {
            if(s[i] == t[i]) {
                mp[s[i] - 'a'][t[i] - 'a']--;
                continue;
            }
            char x = s[i];
            char y = t[i];
            int pos = -1;
            for(int j = i + 1; j <= n; j++) {
                if(s[j] == x) {
                    pos = j;
                    break;
                }
            }
            if(pos != -1) {
                swap(s[pos], t[i]);
                ans.push_back(make_pair(pos, i));
            } else {
                for(int j = i + 1; j <= n; j++) {
                    if(t[j] == x) {
                        pos = j;
                        break;
                    }
                }
                swap(s[pos],t[pos]);
                swap(s[pos], t[i]);
                ans.push_back(make_pair(pos, pos));
                ans.push_back(make_pair(pos, i));
            }
        }
        if(flag) {
            printf("Yes\n");
            printf("%d\n", ans.size());
            for(auto i : ans) {
                printf("%d %d\n", i.first, i.second);
            }
        } else {
            printf("No\n");
        }
    }
    return 0;
}
