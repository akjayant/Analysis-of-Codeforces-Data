#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int M = 1000001;
int n,m,k,T,L,R;
char c[M];
int main()
{
	scanf("%d",&T);
	for(;T;T--)
	{
		int B=0; L=0x3f3f3f3f, R= 0;
		scanf("%d\n%s",&n,c+1);
		for(int i=1;i<=n;i++) if(c[i]=='1') 
		{
			B=1;
			L=min(L,i); R=max(R,i);
		}
		if(!B) 
		{
			printf("%d\n",n);
			continue;
		}
		int res=n+1;
		res=max(res,R*2);
		res=max(res,(n-L+1)*2);
		printf("%d\n",res);
	}
}
