#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(__gcd(x,y)==1)puts("Finite");
		else puts("Infinite");
	}
}

