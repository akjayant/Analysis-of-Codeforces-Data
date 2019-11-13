#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
char str[N]; bool is[N]; int many[10][10],n,ans;
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%s",&n,&many[0][1],&many[0][2],&many[0][3],str+1);
		many[1][1]=many[1][2]=many[1][3]=ans=0;
		for(int i=1;i<=n;i++) is[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='P'&&many[0][3]) many[0][3]--,is[i]=true,ans++;
			if(str[i]=='R'&&many[0][2]) many[0][2]--,is[i]=true,ans++;
			if(str[i]=='S'&&many[0][1]) many[0][1]--,is[i]=true,ans++;
		}
		if(ans<(n+1)/2) {printf("No\n");continue;} printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='P'&&is[i]) printf("S");
			if(str[i]=='P'&&!is[i]) many[0][1]?printf("R"),many[0][1]--:printf("P"),many[0][2]--;
			if(str[i]=='R'&&is[i]) printf("P");
			if(str[i]=='R'&&!is[i]) many[0][1]?printf("R"),many[0][1]--:printf("S"),many[0][3]--;
			if(str[i]=='S'&&is[i]) printf("R");
			if(str[i]=='S'&&!is[i]) many[0][3]?printf("S"),many[0][3]--:printf("P"),many[0][2]--;
		} printf("\n");
	}
}