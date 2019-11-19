#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
const int N = 100010,mod = 1e9 + 7;
ll read() {
	ll x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int a[10][10],n,m,ans;
void check() {
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= m;++j) {
			int cnt = 0;
			if(i > 1) cnt += (a[i][j] == a[i - 1][j]);
			if(i < n) cnt += (a[i + 1][j] == a[i][j]);
			if(j < m) cnt += (a[i][j] == a[i][j + 1]);
			if(j > 1) cnt += (a[i][j] == a[i][j - 1]);
//			puts("!!!");
			if(cnt > 1) return;
		}
	}
	ans++;
}
void dfs(int x,int y) {
	if(x == n + 1) {
		check();
		return;
	}
	int nx = x,ny = y + 1;
	if(y == m) nx++,ny = 1;
	dfs(nx,ny);
	a[x][y] = 1;
	dfs(nx,ny);
	a[x][y] = 0;
}
int f[N],g[N];
int main() {
	n = read(),m = read();
	f[1] = 2,f[2] = 4;
	for(int i = 3;i <= n;++i) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	
	g[1] = 0;
	g[2] = 2;
	
	for(int i = 3;i <= m;++i) {
		g[i] = (g[i - 1] + g[i - 2]) % mod;
	}
	ll sum = 0;
	for(int i = 1;i <= m;++i) {
		sum += g[i];
		sum %= mod;
	}
//	cout<<g[5]<<endl;
	cout<<(f[n] + sum) % mod;
	return 0;
}
