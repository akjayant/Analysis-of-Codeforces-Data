#include<bits/stdc++.h>
using namespace std;
char s[100001];
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
signed main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
	return 0;
}
