#include<bits/stdc++.h>
using namespace std;
#define md 1000000007

char wo[100100];
int co[100100];

main()
{
	scanf("%s",wo);
	co[0]=1;
	for(int i=0;wo[i];i++)
	{
		if(wo[i]=='m'||wo[i]=='w')
		{
			printf("0\n");
			return 0;
		}
		if(i)co[i]=co[i-1];
		if(wo[i]=='n')
		{
			if(i-1>=0&&wo[i-1]=='n')
			{
				if(i-2>=0)co[i]+=co[i-2];
				else co[i]++;
			}
		}
		if(wo[i]=='u')
		{
			if(i-1>=0&&wo[i-1]=='u')
			{
				if(i-2>=0)co[i]+=co[i-2];
				else co[i]++;
			}
		}
		co[i]%=md;
	}
	printf("%d\n",co[strlen(wo)-1]);
}
