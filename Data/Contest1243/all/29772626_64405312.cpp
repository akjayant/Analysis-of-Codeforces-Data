#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
	
}
int T,n,cnt,len,ans[10010][2],loc[10010];
string str1,str2;
char s1[10010],s2[10010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();cnt=len=0;
		cin>>str1>>str2;
		for(int i=1;i<=n;i++)if(str1[i-1]!=str2[i-1])++cnt,s1[cnt]=str1[i-1],s2[cnt]=str2[i-1],loc[cnt]=i;
		if(cnt==0)
		{
			printf("YES\n%d\n",cnt);
			continue;
		}	
		bool flag=0;
		for(int i=1;i<cnt;i++)
			if(s1[i]!=s2[i])
			{
				for(int j=i+1;j<=cnt;j++)
				{
					if(s1[i]==s1[j])
					{
						len++;
						ans[len][0]=j;ans[len][1]=i;
						swap(s1[j],s2[i]);
						break;
					}
				}
				if(s1[i]==s2[i])continue;
				for(int j=i+1;j<=cnt;j++)
				{
					if(s1[i]==s2[j])
					{
						len++;
						ans[len][0]=cnt;ans[len][1]=j;
						swap(s2[j],s1[cnt]);
						len++;
						ans[len][0]=cnt;ans[len][1]=i;
						swap(s1[cnt],s2[i]);
						break;
					}
				}
				if(s1[i]==s2[i])continue;
				flag=1;
				printf("NO\n");
				break;
			}
		if(flag)continue;
		if(s1[cnt]==s2[cnt])
		{
			printf("YES\n");
			printf("%d\n",len);
			for(int i=1;i<=len;i++)printf("%d %d\n",loc[ans[i][0]],loc[ans[i][1]]);
		}
		else printf("NO\n");
	}
	return 0;
}
/*
abc
abc
*/
