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

int n, k, a[N], ans, p1, p2, ls;
char s1[N], s2[N];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
    #endif

    scanf("%d", &k);

    while(k--) {
        scanf("%d", &n);
        scanf("%s%s", s1, s2);

//        if(strcmp(s1, s2) == 0) puts("Yes");
//        else {
        ans = 0; p1 = -1; p2 = -1;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                ans++;
                if(p1 == -1) p1 = i;
                else if(p2 == -1) p2 = i;
            }
        }

        if(ans == 0) puts("Yes");
        else if(ans > 2 || ans == 1) puts("No");
        else {
            if(s2[p1] == s2[p2] && s1[p1] == s1[p2]) {
                puts("Yes");
            }
            else puts("No");
        }

    }

    return 0;
}
