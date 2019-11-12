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
#define N 1010
#define M 2000100
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1);
#define fi first
#define se second
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)

int n, k, a[N], ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
    #endif

    scanf("%d", &k);

    while(k--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", &a[i]);

        sort(a +1, a+1+n);
        ans = 0;
        for(int i = n; i >= 1; i--) {
            ans = max(ans, min(n-i+1, a[i]));
        }

        printf("%d\n", ans);
    }

    return 0;
}
