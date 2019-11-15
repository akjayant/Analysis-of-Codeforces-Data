#include <cstdio>
#include <cstring>
const int S=103;
int t,a,b,c,f[S][S][S];
inline int ma(int a,int b){return a>b?a:b;}
inline int dfs(int a,int b,int c)
{
	int &tp=f[a][b][c];
	if (tp!=-1) return tp;
	tp=0;
	if (a>=1 && b>=2) tp=ma(tp,dfs(a-1,b-2,c)+3);
	if (b>=1 && c>=2) tp=ma(tp,dfs(a,b-1,c-2)+3);
	return tp;
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",dfs(a,b,c));
	}
	return 0;
}