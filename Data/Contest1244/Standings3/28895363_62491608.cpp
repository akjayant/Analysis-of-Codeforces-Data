#include<cstdio>

using namespace std;

typedef long long LL;

const LL INF = 1e15;
const int N = 100005;

int n, u, v;
LL c[N][4];

struct Edge{
	int nxt, to;
}edge[N<<1];
int head[N], edgeNum, deg[N];
void addEdge(int from, int to){
	edge[++edgeNum].nxt = head[from];
	edge[edgeNum].to = to;
	head[from] = edgeNum;
	deg[to]++;
}

LL col[N], anscol[N];
void dfs(int pre, int now, int precolor, int nowcolor){
	col[now] = nowcolor;
	col[pre] = precolor;
	int thiscolor = 6 - precolor - nowcolor;
	for(int i = head[now]; i; i = edge[i].nxt){
		if(edge[i].to == pre)	continue;
		dfs(now, edge[i].to, nowcolor, thiscolor);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &c[i][1]);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &c[i][2]);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &c[i][3]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	for(int i = 1; i <= n; i++)
		if(deg[i] > 2)
			return puts("-1"), 0;
	int h = 0;
	for(h = 1; h <= n; h++)
		if(deg[h] == 1)
			break;
	LL ans = INF, res = 0;
	int h2 = edge[head[h]].to;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			if(i == j)	continue;
			res = 0;
			dfs(h, h2, i, j);
			for(int k = 1; k <= n; k++)
				res += c[k][col[k]];
			if(res < ans){
				ans = res;
				for(int k = 1; k <= n; k++)
					anscol[k] = col[k];
			}
		}
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= n; i++)
		printf("%lld ", anscol[i]);
	return 0;
}
