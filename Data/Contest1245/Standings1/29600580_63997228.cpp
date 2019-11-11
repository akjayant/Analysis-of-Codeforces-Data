#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;

int T,a,b;

int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	//freopen("read.in","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		if (gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	}
}