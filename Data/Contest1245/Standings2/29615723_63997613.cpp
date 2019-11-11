#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main()
{
	int n;scanf("%d",&n);
	int a,b;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		if(gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	};
	return 0;
}