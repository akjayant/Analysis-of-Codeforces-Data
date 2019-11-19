#include<bits/stdc++.h>
using namespace std;
char s[10000];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				int p=max(i*2,(n-i+1)*2);
				ans=max(ans,p);
			}
		}
		cout<<ans<<endl;
	}
}
