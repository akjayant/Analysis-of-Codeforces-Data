#include <cstdio>
#include <algorithm>
using namespace std;
int n,pla[100010]; char str1[100010],str2[100010];
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%s",&n,str1+1,str2+1),pla[0]=0;
		for(int i=1;i<=n;i++) if(str1[i]!=str2[i]) pla[++pla[0]]=i;
		if(pla[0]!=2) {printf("No\n");continue;}
		if(str1[pla[1]]!=str1[pla[2]]||str2[pla[1]]!=str2[pla[2]]) {printf("No\n");continue;}
		printf("Yes\n");
	}
}