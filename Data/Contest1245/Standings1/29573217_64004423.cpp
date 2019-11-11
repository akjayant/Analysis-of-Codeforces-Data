#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

char a[101];
char ans[101];
int T,A,B,C,n,i,j,k,l,tot,a2,b2,c2;

int main()
{
//	freopen("b.in","r",stdin);
	
	scanf("%d",&T);
	for (;T;--T)
	{
		memset(ans,0,sizeof(ans));
		tot=0;
		
		scanf("%d",&n);
		scanf("%d%d%d",&A,&B,&C);
		scanf("%s",a);
		
		fo(i,0,n-1)
		{
			switch (a[i])
			{
				case 'R':{
					if (B)
					{
					--B,++tot,ans[i]='P';
					}
					break;
				}
				case 'P':{
					if (C)
					{
					--C,++tot,ans[i]='S';
					}
					break;
				}
				case 'S':{
					if (A)
					{
					--A,++tot,ans[i]='R';
					}
					break;
				}
			}
		}
		
		if (tot>=ceil((double)n/2)-0.01)
		{
			printf("YES\n");
			
			fo(i,0,n-1)
			if (ans[i]=='R' || ans[i]=='P' || ans[i]=='S')
			printf("%c",ans[i]);
			else
			{
				if (A)
				{
					printf("R");
					--A;
				}
				else
				if (B)
				{
					printf("P");
					--B;
				}
				else
				if (C)
				{
					printf("S");
					--C;
				}
			}
			printf("\n");
		}
		else
		printf("NO\n");
	}
}