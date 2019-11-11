#include <bits/stdc++.h>
using namespace std;
int main()
{
	int _,a,b;scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&a,&b);
		if(a==1&&b==1)printf("Finite\n");
		else puts(__gcd(a,b)==1?"Finite":"Infinite");
	}
	return 0;
}