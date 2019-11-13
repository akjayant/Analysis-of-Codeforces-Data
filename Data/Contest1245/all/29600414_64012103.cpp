#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int opt=0,k=min(n,m);
		for(int i=2;i<=k;i++)
		{
			if(n%i==0&&m%i==0)
			{opt=1;break;}
		}
		if(opt)printf("Infinite\n");
		else printf("Finite\n");
	}
	
	
	
	return 0;
}