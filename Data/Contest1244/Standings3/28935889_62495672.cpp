#include <bits/stdc++.h>
#define N 100005

using namespace std;

int col[4], acol[4], anscol[N];
int n, deg[N];
int head[N], nex[N << 1], to[N << 1], te;
long long c[N][4];

#define writesp(x) (write(x), putchar(' '))
#define writeln(x) (write(x), putchar('\n'))
template <typename T> inline void cmin(T &u, const T v) { if(u > v) u = v; }
template <typename T> inline void read(T &x) {
	x = 0; bool sgn = false; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (sgn = true), ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	if(sgn) x = -x;
}
inline int Rd() { static int x; return read(x), x; }
template <typename T> inline void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	static char buf[40]; int o = 0;
	for(x; x > 9; x /= 10, ++o) buf[o] = x % 10 + '0'; buf[o] = x + '0';
	for(o; ~o; --o) putchar(buf[o]);
	return;
}

inline void Ae(int u, int v) {
	nex[++te] = head[u], head[u] = te;
	to[te] = v, ++deg[v];
	return;
}

long long dfs(int u, int fa, int o) {
	if(o > 3) o -= 3;
	long long res = c[u][col[o]];
	for(int i = head[u]; i; i = nex[i]) {
		int v = to[i];
		if(v == fa) continue;
		res += dfs(v, u, o + 1);
	}
	return res;
}
void pr(int u, int fa, int o) {
	if(o > 3) o -= 3;
	anscol[u] = acol[o];
	for(int i = head[u]; i; i = nex[i]) {
		int v = to[i];
		if(v == fa) continue;
		pr(v, u, o + 1);
	}
	return;
}

int main() {
	read(n);
	for(int o = 1; o <= 3; ++o) {
		for(int i = 1; i <= n; ++i) {
			read(c[i][o]);
		}
	}
	
	int u, v;
	for(int i = 1; i < n; ++i) {
		read(u), read(v);
		Ae(u, v), Ae(v, u);
		if(deg[u] > 2 || deg[v] > 2) {
			puts("-1");
			return 0;
		}
	}
	
	int root = -1;
	long long ans = 1e17, res;
	for(int i = 1; i <= n; ++i) if(deg[i] == 1) root = i;
	for(int i = 1; i <= 3; ++i) {
		for(int j = 1; j <= 3; ++j) {
			for(int k = 1; k <= 3; ++k) {
				if(i == j || j == k || i == k) continue;
				col[1] = i, col[2] = j, col[3] = k;
				res = dfs(root, 0, 1);
				if(ans > res) {
					ans = res;
					acol[1] = col[1];
					acol[2] = col[2];
					acol[3] = col[3];
				}
			}
		}
	}
	writeln(ans);
	pr(root, 0, 1);
	for(int i = 1; i <= n; ++i) {
		printf("%d", anscol[i]);
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}