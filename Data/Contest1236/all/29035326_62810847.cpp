#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int rd(){
	int x=0,flg=1;
	char c=getchar();
	for (;(c<48||c>57)&&c!='-';c=getchar());
	if (c=='-') flg=-1,c=getchar();
	for (;c>47&&c<58;x=x*10+c-48,c=getchar());
	return flg*x;
}
typedef long long LL;
typedef pair<int,int> pii;
int n,m,a[310][310];
int main()
{
	scanf("%d",&n);
	for (int j=1;j<=n;++j)
		if (j&1)
			for (int i=1;i<=n;++i)
				a[i][j]=++m;
		else
			for (int i=n;i>=1;--i)
				a[i][j]=++m;
	for (int i=1;i<=n;puts(""),++i)
		for (int j=1;j<=n;++j)
			printf("%d ",a[i][j]);
	return 0;
}