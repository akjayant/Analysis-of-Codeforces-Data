#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<iterator>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
#define eps 1e-8

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 100100;
const int mod = 998244353;
int c[4][maxn], vis[maxn], in[maxn];
vector<int> g[maxn], s[5];
void dfs(int fa, int u);
LL getsum(int i, int j, int k);

int main()
{
	int n, i, j, k, fr, to;
	LL mi;
	scanf("%d", &n);
	for(i=1;i<=3;i++)
		for(j=1;j<=n;j++)
			scanf("%d", &c[i][j]);
	for(i=1;i<n;i++)
	{
		scanf("%d %d", &fr, &to);
		in[fr]++, in[to]++;
		g[fr].push_back(to);
		g[to].push_back(fr);
	}
	for(i=1;i<=n;i++)
		if(in[i]>2)break;
	if(i<=n)printf("-1\n");
	else{
		for(i=1;i<=n;i++)
		if(in[i] == 1){
			vis[i] = 1;
			dfs(i, g[i][0]);break;
		}
		for(i=1;i<=n;i++)
			s[vis[i]].push_back(i);
		mi = getsum(1, 2, 3);
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
				for(k=1;k<=3;k++)
				{
					LL sum = getsum(i, j, k);
					if(sum != -1 && sum < mi)
					{
						mi = sum;
						for(int z=0;z<s[1].size();z++)
							vis[s[1][z]] = i;
						for(int z=0;z<s[2].size();z++)
							vis[s[2][z]] = j;
						for(int z=0;z<s[3].size();z++)
							vis[s[3][z]] = k;
					}
				}
		printf("%I64d\n%d", mi, vis[1]);
		for(i=2;i<=n;i++)
			printf(" %d", vis[i]);
		printf("\n");
	}
	return 0;
}

void dfs(int fa, int u)
{
	vis[u] = vis[fa]+1;
	while(vis[u] > 3)vis[u]-=3;
	for(int i=0;i<g[u].size();i++)
		if(!vis[g[u][i]])
			dfs(u, g[u][i]);
}

LL getsum(int i, int j, int k)
{
	if(i == j || i == k || j==k)return -1;
	int z;
	LL sum = 0;
	for(z=0;z<s[1].size();z++)
		sum += c[i][s[1][z]];
	for(z=0;z<s[2].size();z++)
		sum += c[j][s[2][z]];
	for(z=0;z<s[3].size();z++)
		sum += c[k][s[3][z]];
	return sum;
}
