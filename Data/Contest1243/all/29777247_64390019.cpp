#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define N 10010
#define M 2000100
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1);
#define fi first
#define se second
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)

int n, k, a[N], ans, p1, p2, ls, cnt[30];
char s1[N], s2[N];
P m[N*2];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
    #endif

    scanf("%d", &k);

    while(k--) {
        scanf("%d", &n);
        scanf("%s%s", s1, s2);
        memset(cnt, 0, sizeof cnt);

        for(int i = 0; i < n; i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']++;
        }

        bool f = true;
        for(int i = 0; i < 28; i++) {
            if(cnt[i] & 1) f = false;
        }
        if(!f) {
            puts("No"); continue;
        }

        ans = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i]) continue;
            int j = i + 1;
            for(; j < n; j++) {
                if(s1[j] == s1[i]) break;
            }
            if(j == n) {
                for(j = i + 1; j < n; j++) {
                    if(s2[j] == s1[i]) break;
                }
                m[ans++] = P(j, j); swap(s2[j], s1[j]);
                m[ans++] = P(j, i); swap(s1[j], s2[i]);
            }
            else {
                m[ans++] = P(j, i); swap(s1[j], s2[i]);
            }
        }
//cout << " n " << n << s1 << ' ' << s2 <<' ' << m[] endl;
        printf("Yes\n%d\n", ans);
        for(int i = 0; i < ans; i++) {
            printf("%d %d\n", m[i].fi+1, m[i].se+1);
        }
    }

    return 0;
}
