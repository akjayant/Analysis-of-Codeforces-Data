#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t;
char s[105];
char ans[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b,c,opt=0;
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s);
		for(int i=0;i<n;i++)
		{
			ans[i]=0;
			if(s[i]=='R'&&b){ans[i]='P';b--;opt++;}
			else if(s[i]=='P'&&c){ans[i]='S';c--;opt++;}
			else if(s[i]=='S'&&a){ans[i]='R';a--;opt++;}
			
		}
		if(opt*2<n){printf("NO\n");continue;}
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			if(!ans[i])
			{
				if(a){ans[i]='R';a--;}
				else if(b){ans[i]='P';b--;}
				else {ans[i]='S';c--;}
			}
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}