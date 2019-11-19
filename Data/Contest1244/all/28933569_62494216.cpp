#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long LL;

const int N = 3e5 + 10;
const LL INF = 1e18;

int n;
int w[3][N] , col[N] , final[N] , tans[N];
vector< int > seq;
vector< int > g[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

inline void DFS(int u , int fa) {
		seq.push_back(u);
		for (auto v : g[u]) {
				if (v == fa) continue;
				DFS(v , u);
		}
}

int main() {
		
		read(n);
		for (int i = 1; i <= n; ++i) read(w[0][i]);
		for (int i = 1; i <= n; ++i) read(w[1][i]);
		for (int i = 1; i <= n; ++i) read(w[2][i]);
		for (int i = 1; i < n; ++i) {
				int x , y;
				read(x); read(y);
				g[x].push_back(y);
				g[y].push_back(x);
		}
		for (int i = 1; i <= n; ++i)
				if (g[i].size() > 2) {
						printf("-1\n");
						return 0;
				}
		int rt = 0;
		for (int i = 1; i <= n; ++i)
				if (g[i].size() == 1) rt = i;
		if (!rt) {
				printf("-1\n");
				return 0;
		}
		DFS(rt , 0);
		LL res = INF;
		for (int c1 = 0; c1 < 3; ++c1)
		for (int c2 = 0; c2 < 3; ++c2) {
				if (c1 == c2) continue;
				col[1] = c1; col[2] = c2;
				for (unsigned i = 2; i < (int)seq.size(); ++i) {
						map<int , int> mp; mp.clear();
						mp[col[i - 1]] = mp[col[i]] = 1;
						if (!mp[0]) col[i + 1] = 0;
						else if (!mp[1]) col[i + 1] = 1;
						else col[i + 1] = 2;
				}
				LL ans = 0;
				for (unsigned i = 0; i < seq.size(); ++i)
						ans += w[col[i + 1]][seq[i]];
				if (ans < res) {
						memcpy(tans , col , sizeof(tans));
						res = ans;
				}
		}
		printf("%I64d\n" , res);
		for (unsigned i = 0; i < seq.size(); ++i)
				final[seq[i]] = tans[i + 1];
		for (int i = 1; i <= n; ++i) 
				printf("%d " , final[i] + 1);
		printf("\n");
		
	  return 0;
	
}
