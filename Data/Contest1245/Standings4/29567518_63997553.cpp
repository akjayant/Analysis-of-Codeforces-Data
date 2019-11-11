#include <cstdio>
using namespace std;
int gcd(int x,int y)
{
	if (!y) return x; else return(gcd(y,x%y));
}
int t,x,y;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&x,&y);
		if (gcd(x,y)!=1) printf("Infinite\n"); else printf("Finite\n"); 
	} 
} 