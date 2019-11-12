#include<bits/stdc++.h>
#define ma 500000

using namespace std;

int kk,t,n,flag;
char d1[ma],d2[ma];
int pd(char c,char d,int sta)
{
	int ch=0;
	if(sta==n) return 0;
	for(int i=sta;i<n;i++)
	{
		if(d1[i]!=d2[i])
		{
			if(d1[i]!=c||ch||d2[i]!=d) return 0;
			ch=1;
		}
	}
	return ch;
}
int main()
{
	
	scanf("%d",&t);
	for(int i=1;i<=100;i++) kk+=i;
	while(t--)
	{
		scanf("%d%s%s",&n,d1,d2);
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(d1[i]!=d2[i])
			{
				flag=1;
				if(pd(d1[i],d2[i],i+1))
					printf("Yes\n");
				else printf("No\n");
				break;
			}	
		}
		if(!flag) printf("Yes\n");
	}
} 