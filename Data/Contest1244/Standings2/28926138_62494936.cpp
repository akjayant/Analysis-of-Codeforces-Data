#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN=110000;
int c[3][MAXN], d[MAXN], p[MAXN];
vector<int> g[MAXN];
int main()
{
//	freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);
	int n, s;
	scanf("%d", &n);
	for (int i=0; i<3; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &c[i][j]);
	for (int i=1; i<n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1; i<=n; i++)
		if (g[i].size()>2)
		{
			puts("-1");
			return 0;
		}
		else if (g[i].size()==1) s=i;
	for (int i=s, l=0, k=1; k<=n; k++)
	{
		d[k]=i; p[i]=k;
		for (int j=0; j<g[i].size(); j++)
			if (g[i][j]!=l) { l=i, i=g[i][j]; break; }
	}
	ll ans=1E18; int r[3], t[3];
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
			{
				if (i==j||i==k||j==k) continue;
				t[0]=i; t[1]=j; t[2]=k;
				ll sum=0;
				for (int l=1; l<=n; l++) sum+=c[t[l%3]][d[l]];
				if (sum<ans) ans=sum, r[0]=i, r[1]=j, r[2]=k;
			}
	printf("%I64d\n", ans);
	for (int i=1; i<=n; i++) printf("%d ", r[p[i]%3]+1);
	putchar('\n');
	return 0;
}