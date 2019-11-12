#include<bits/stdc++.h>
#define mp(a,b) memset(a,b,sizeof(a))

using namespace std;

int t,n,cnt,flag,num[30],l[500],r[500];
char s1[500],s2[500];
void deal()
{
	for(int i=0;i<n;i++)
	{
		if(s1[i]!=s2[i])
		{
			for(int j=i+1;j<n;j++)
			{
				if(s1[j]==s1[i])
				{
					cnt++;
					swap(s1[j],s2[i]);
					l[cnt]=j+1; r[cnt]=i+1;
					break;
				}
				if(s2[j]==s1[i])
				{
					cnt++;
					swap(s2[j],s1[j]);
					l[cnt]=r[cnt]=j+1;
					cnt++;
					swap(s1[j],s2[i]);
					l[cnt]=j+1; r[cnt]=i+1;
					break;
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s%s",&n,s1,s2);
		mp(num,0);
		flag=cnt=0;
		for(int i=0;i<n;i++){
			num[s1[i]-'a']++;
			num[s2[i]-'a']++;
		}
		for(int i=0;i<26;i++)
			if(num[i]%2)
			{
				flag=1;
				printf("No\n");	
				break;
			} 
		if(!flag) 
		{
			printf("Yes\n");
			deal();
			if(cnt!=0)
			{
				printf("%d\n",cnt);
				for(int i=1;i<=cnt;i++)
				printf("%d %d\n",l[i],r[i]);	
			}
			else
			{
				printf("1\n1 1\n");
			}	
		}
	}
	
}