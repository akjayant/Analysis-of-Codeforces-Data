#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<ctime>
#define lowbit(x) x&-x
#define inf 2147483647
#define N 200005
using namespace std;
int gcd(int x,int y){return (!y)?x:gcd(y,x%y);}
int main()
{
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
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
