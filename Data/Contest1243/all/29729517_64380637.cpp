#include<bits/stdc++.h>
#define ma 500000

using namespace std;

int t,n,flag;
char s1[ma],s2[ma];
int deal(char c,char d,int sta)
{
	int ch=0;
	if(sta==n) return 0;
	for(int i=sta;i<n;i++)
	{
		if(s1[i]!=s2[i])
		{
			if(s1[i]!=c||ch||s2[i]!=d) return 0;
			ch=1;
		}
	}
	return ch;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s%s",&n,s1,s2);
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(s1[i]!=s2[i])
			{
				flag=1;
				if(deal(s1[i],s2[i],i+1))
					printf("Yes\n");
				else printf("No\n");
				break;
			}	
		}
		if(!flag) printf("Yes\n");
	}
} 