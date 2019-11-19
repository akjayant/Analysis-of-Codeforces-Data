#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define fi first
#define se second
#define lson (rt<<1)
#define rson (rt<<1|1)
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)

const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 200000 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
LL dp1[maxn], dp2[maxn];

int main() {
    scanf("%d%d", &n, &m);
    dp1[1] = 2, dp1[2] = 4;
    for(int i = 3; i <= max(n, m); ++i) dp1[i] = (dp1[i-1] + dp1[i-2]) % mod;
    dp2[1] = dp1[n];
    for(int i = 2; i <= m; ++i) dp2[i] = ((dp1[i] + dp2[1] - 2) % mod + mod) % mod;
    printf("%lld\n", dp2[m]);
    return 0;
}