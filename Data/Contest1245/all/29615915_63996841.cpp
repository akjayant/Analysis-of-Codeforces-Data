#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int gcd(int a,int b){return b? gcd(b,a%b):a;}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (gcd(a,b)==1) puts("Finite");
		else puts("Infinite"); 
	}
	return 0;
}
