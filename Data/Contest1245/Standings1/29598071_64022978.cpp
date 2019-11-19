#include<bits/stdc++.h>
const int maxn = 20;
int h[maxn][maxn];
typedef double db;
db f[maxn][maxn];
db g[maxn][maxn];
void go(int&x,int&y){
	if(x & 1){
		y == 10 ? ++ x : ++ y;
	} else {
		y == 1 ? ++ x : -- y;
	}
}
void dp(int i,int j){
	if(i == 10 && j == 1) return ;
	int x = i,y = j;
	go(x,y);
	dp(x,y);
	int cnt = 0;
	for(int k = 1,a = i,b = j;k <= 6;++k){
		go(a,b);
		if(a <= 10){
			f[i][j] += f[a][b];
			g[i][j] += f[a][b];
			++cnt;
		}
	}
	f[i][j] += 6;
	g[i][j] += 6;
	f[i][j] /= cnt;
	g[i][j] /= cnt;
	if(h[i][j]) f[i][j] = std::min(f[i][j],g[i + h[i][j]][j]);
}
int main(){
	for(int i = 10;i >= 1;--i) for(int j = 1;j <= 10;++j)
		std::cin >> h[i][j];
	dp(1,1);
	printf("%.20lf",f[1][1]);
}
