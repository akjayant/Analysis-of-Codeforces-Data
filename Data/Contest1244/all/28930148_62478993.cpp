#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;

LL n,m,k;
LL c[4][800005] = {0};
LL ans = 0;
string s;

LL ec = 0,to[800005],nxt[800005],hed[200005] = {0};
LL deg[400005] = {0};
void add_edge(LL f,LL t){
	++ ec; to[ec] = t; nxt[ec] = hed[f]; hed[f] = ec;
	deg[t] ++;
}

LL col[200005] = {0};
LL rec[200005] = {0};

LL chg(LL x,LL y){
	if(x == 1 && y == 2) return 3;
	if(x == 1 && y == 3) return 2;
	if(x == 2 && y == 3) return 1;
	if(y == 1 && x == 2) return 3;
	if(y == 1 && x == 3) return 2;
	if(y == 2 && x == 3) return 1;
}

void dfs(LL u,LL f,LL uc,LL fc){
	for(LL i = hed[u];i;i = nxt[i]){
		LL v = to[i];
		if(v == f) continue;
		col[v] = chg(uc,fc);
		dfs(v,u,col[v],uc);
	}
}

int main(){
	LL a,b;
	ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> c[1][i];
	for(LL i = 1;i <= n;i ++) cin >> c[2][i];
	for(LL i = 1;i <= n;i ++) cin >> c[3][i];
	for(LL i = 1;i < n;i ++){
		cin >> a >> b;
		add_edge(a,b);
		add_edge(b,a);
	}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(LL c1 = 1;c1 <= 3;c1 ++){
		for(LL c2 = 1;c2 <= 3;c2 ++){
			if(c1 == c2) continue;
			col[a] = c1; col[b] = c2;
			dfs(a,b,c1,c2);
			dfs(b,a,c2,c1);
			LL cnt = 0;
			for(LL i = 1;i <= n;i ++){
				cnt += c[col[i]][i];
			}
			if(cnt < ans){
				ans = cnt;
				for(LL i = 1;i <= n;i ++) rec[i] = col[i];
			}
		}
	}
	for(LL i = 1;i <= n;i ++){
		if(deg[i] >= 3){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	for(LL i = 1;i <= n;i ++) cout << rec[i] << (i == n ? '\n' : ' '); 
	return 0;
}