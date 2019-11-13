#include<iostream>
#include<cstdio>
using namespace std;
char s[10005],t[10005];
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n;
		scanf("%d%s%s",&n,s,t);
		int pos1=-1,pos2=-1,pos3=-1;
		for(int i=0;s[i];i++)
		{
			if(s[i]!=t[i])
			{
				if(pos1<0)pos1=i;
				else if(pos2<0)pos2=i;
				else pos3=i;
			}
		}
		if(pos3!=-1)puts("No");
		else if((pos1==-1&&pos2==-1)||(pos1!=-1&&pos2!=-1&&s[pos1]==s[pos2]&&t[pos1]==t[pos2]))puts("Yes");
		else puts("No");
	}
	return 0;
}
