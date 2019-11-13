#include<bits/stdc++.h>
using namespace std;

int t,n,cnt,kk,flag,num[30],l[500],r[500],pd[1500];
char s[1500],d1[500],d2[500];
void deal()
{
	for(int i=0;i<n;i++)
	{
		kk+=i;
		if(d1[i]!=d2[i])
		{
			for(int j=i+1;j<n;j++)
			{
				if(d1[j]==d1[i])
				{
					kk--;
					pd[j]=d1[j]-d1[i];
					cnt++;
					swap(d1[j],d2[i]);
					l[cnt]=j+1; r[cnt]=i+1;
					break;
				}
				if(d2[j]==d1[i])
				{
					cnt++;
					swap(d2[j],d1[j]);
					l[cnt]=r[cnt]=j+1;
					cnt++;
					swap(d1[j],d2[i]);
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
		scanf("%d%s%s",&n,d1,d2);
		memset(num,0,sizeof(num));
		flag=cnt=0;
		for(int i=0;i<n;i++){
			num[d1[i]-'a']++;
			num[d2[i]-'a']++;
		}
		for(int i=0;i<26;i++)
			if(num[i]%2)
			{
				kk*=10;
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
				if(pd[1]>0) pd[1]--;
				printf("1\n1 1\n");
			}	
		}
	}
	
}