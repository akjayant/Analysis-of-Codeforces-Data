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

LL n;

int main() {
    scanf("%lld", &n);
    int cnt = 0;
    LL x = n, ans = 0;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(x % i == 0) {
            ++cnt;
            ans = i;
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1 && x != n) ++cnt, ans = x;
    if(cnt == 0) printf("%lld\n", n);
    else if(cnt == 1) printf("%lld\n", ans);
    else printf("1\n");
    return 0;
}
