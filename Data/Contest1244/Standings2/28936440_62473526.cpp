#include<bits/stdc++.h>
using namespace std;
const int size=1005;
char s[size];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
				ans=max({ans,2*i,2*(n-i+1)});
		}
		printf("%d\n",ans);
	}
}

		
			