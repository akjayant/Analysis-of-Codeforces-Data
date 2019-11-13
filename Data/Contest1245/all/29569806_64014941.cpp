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
const int maxn = 100 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int t, n, a, b, c, r, p, s;
int vis[maxn];
char str[maxn], ans[maxn];

int main() {
    scanf("%d", &t);
    while(t--) {
    	scanf("%d%d%d%d", &n, &a, &b, &c);
    	r = p = s = 0;
    	scanf("%s", str + 1);
    	for(int i = 1; i <= n; ++i) {
    		vis[i] = 0;
    		if(str[i] == 'R') ++r;
    		else if(str[i] == 'P') ++p;
    		else ++s;
    	}
    	int cnt = min(a, s) + min(b, r) + min(c, p);
    	if(cnt < (n + 1) / 2) puts("NO");
    	else {
    		puts("YES");
    		for(int i = 1; i <= n; ++i) {
    			if(str[i] == 'R') {
    				if(b) ans[i] = 'P', --b, vis[i] = 1;
    			} else if(str[i] == 'P') {
    				if(c) ans[i] = 'S', --c, vis[i] = 1;
    			} else {
    				if(a) ans[i] = 'R', --a, vis[i] = 1;
    			}
    		}
    		for(int i = 1; i <= n; ++i) {
    			if(!vis[i]) {
    				if(a) {
    					--a;
    					ans[i] = 'R';
    				} else if(b) {
    					--b;
    					ans[i] = 'P';
    				} else {
    					--c;
    					ans[i] = 'S';
    				}
    			}
    		}
    		for(int i = 1; i <= n; ++i) printf("%c", ans[i]);printf("\n");
    	}
    }
    return 0;
}
