#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
const long long INF = (1LL << 58);
long long city[2005][2];
long long c[2005];
long long k[2005];
long long g[2005][2005];
int tmp[2005][2005];
long long lowc[2005];
int vis[2005];
int f[2005];
queue<int> q1;
queue<pair<int, int> > q2;
long long Abs(long long m){
	if(m >= 0) return m;
	else return -m;
} 
int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d %d", &city[i][0], &city[i][1]); 
	}
	for(i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	for(i = 1; i <= n; i++){
		scanf("%d", &k[i]);
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j) g[i][j] = 0;
			else{
				g[i][j] = (k[i] + k[j]) * (Abs(city[i][0] - city[j][0]) + Abs(city[i][1] - city[j][1]));
				if(g[i][j] > c[j]){
					g[i][j] = c[j];
					tmp[i][j] = 1;
				}
			} 
		}
	}
	for(i = 1; i <= n; i++){
		g[0][i] = c[i];
		tmp[0][i] = 1;
	}
	lowc[0] = 0;
	vis[0] = 1;
	for(i = 1; i <= n; i++){
		lowc[i] = g[0][i];
		f[i] = 0;
	}
	int u;
	long long d, ans = 0;
	for(i = 1; i <= n; i++){
		d = INF;
		u = -1;
		for(j = 1; j <= n; j++){
			if(!vis[j] && lowc[j] < d){
				d = lowc[j];
				u = j;
			}
		}
		vis[u] = 1;
		ans += lowc[u];
		if(tmp[f[u]][u] == 1){
			q1.push(u); 
		}
		else{
			q2.push(make_pair(f[u], u)); 
		}
		for(j = 1; j <= n; j++){
			if(!vis[j] && lowc[j] > g[u][j]){
				lowc[j] = g[u][j];
				f[j] = u;
			}
		}
	}
	int t1 = q1.size();
	int t2 = q2.size();
	printf("%lld\n", ans);
	printf("%d\n", t1);
	while(!q1.empty()){
		printf("%d ", q1.front());
		q1.pop();
	}
	printf("\n");
	printf("%d\n", t2);
	while(!q2.empty()){
		printf("%d %d\n", q2.front().first, q2.front().second);
		q2.pop();
	}
	return 0;
}