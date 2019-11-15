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

int T, n;
char s[maxn], t[maxn];
vector<int> vec;

int main() {
    scanf("%d", &T);
    while(T--) {
    	scanf("%d%s%s", &n, s, t);
    	vec.clear();
    	for(int i = 0; i < n; ++i) {
    		if(s[i] != t[i]) vec.push_back(i);
    	}
    	if(vec.size() > 2 || vec.size() == 1) {
    		puts("No");
    		continue;
    	}
    	if(vec.size() == 0) {
    		puts("Yes");
    		continue;
    	}
    	if(s[vec[0]] == s[vec[1]] && t[vec[0]] == t[vec[1]]) {
    		puts("Yes");
    	} else puts("No");
    }
    return 0;
}
