#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

inline int max(int x,int y)
{
	return x>y?x:y;
}
char s[10005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++)
			if(s[i]=='1') ans=max(ans,max(i*2,(n-i+1)*2));
		printf("%d\n",ans);
	}
	return 0;
} 
