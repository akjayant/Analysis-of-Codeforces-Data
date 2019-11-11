#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		int g=gcd(a,b);
		if(g==1) printf("Finite\n");
		else printf("Infinite\n");
	}
}
