#include <cstdio>
#include <algorithm>
using namespace std;
int num[11000];
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		for(int i=n;i;i--)
		{
			int many=0;
			for(int j=1;j<=n;j++) if(num[j]>=i) many++;
			if(many>=i) {printf("%d\n",i);break;}
		}
	}
}