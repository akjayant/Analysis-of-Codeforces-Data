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
const int maxn = 100000 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, u, v;
vector<int> edge[maxn];
int vis[maxn], mark[maxn];
set<int> st;

void bfs(int u) {
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i];
			mark[v] = 1;
		}
		for(auto i = st.begin(); i != st.end(); ) {
			if(!mark[*i]) {
				q.push(*i);
				st.erase(i++);
			} else {
				mark[*i] = 0;
				i++;
			}
		}
	}
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
    	scanf("%d%d", &u, &v);
    	edge[u].push_back(v);
    	edge[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) st.insert(i);
    for(int i = 1; i <= n; ++i) {
    	if(!vis[i]) {
    		++ans;
    		bfs(i);
    	}
    }
    printf("%d\n", ans-1);
    return 0;
}
