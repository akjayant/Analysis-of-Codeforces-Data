#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1086;
inline bool cmp(int aa,int bb)
{
	return aa>bb;
}
int a[N];
int n,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		int ok=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<i)
			{
				printf("%d\n",i-1);
				ok=1;
				break;
			}
		}
		if(!ok)
			printf("%d\n",n);
	}
	return 0;
}
