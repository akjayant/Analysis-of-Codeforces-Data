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

int fib[maxn];
char str[maxn];
vector<int> vec;

int main() {
	fib[0] = fib[1] = 1;
	for(int i = 2; i < maxn; ++i) {
		fib[i] = (fib[i-1] + fib[i-2]) % mod;
	}
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    int flag = 1;
    for(int i = 1; i <= n; ++i) {
    	if(str[i] == 'm' || str[i] == 'w') {
    		flag = 0;
    		break;
    	}
    }
    if(!flag) return printf("0\n") * 0;
    for(int i = 1; i <= n; ++i) {
    	if(str[i] != 'u' && str[i] != 'n') continue;
    	int cnt = 0;
    	if(str[i] == 'n') {
    		while(i <= n && str[i] == 'n') {
    			++cnt;
    			++i;
    		}
    		--i;
    		vec.push_back(cnt);
    	} else {
    		while(i <= n && str[i] == 'u') {
    			++cnt;
    			++i;
    		}
    		--i;
    		vec.push_back(cnt);
    	}
    }
    LL ans = 1;
    for(auto x : vec) {
    	ans = ans * fib[x] % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
