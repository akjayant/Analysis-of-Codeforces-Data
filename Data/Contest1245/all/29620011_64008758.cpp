#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int t,a[4],n;
vector<char> notuse;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		notuse.clear();
		scanf("%d",&n);
		for(int i=1;i<=3;i++)
			scanf("%d",&a[i]);
		char ans[110];
		int sum=0,Index=0;
		char s[110];
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			if(s[i]=='R'&&a[2]>0){a[2]--;ans[i]='P';sum++;}
			else if(s[i]=='P'&&a[3]>0){a[3]--;ans[i]='S';sum++;}
			else if(s[i]=='S'&&a[1]>0){a[1]--;ans[i]='R';sum++;}
			else ans[i]=0;
		}
		while(a[1]>0){a[1]--;notuse.push_back('R');}
		while(a[2]>0){a[2]--;notuse.push_back('P');}
		while(a[3]>0){a[3]--;notuse.push_back('S');}
		if(sum>=(n+1)/2)
		{
			printf("YES\n");
			for(int i=1;i<=len;i++)
			{
				if(ans[i]) printf("%c",ans[i]);
				else printf("%c",notuse[Index++]);
			}
			printf("\n");
		}
		else printf("NO\n");
	}
}