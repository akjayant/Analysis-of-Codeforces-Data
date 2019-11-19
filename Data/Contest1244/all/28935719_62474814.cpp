#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
int f[M],n;
char s[M];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=n;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
				ans=max(ans,max(i*2,(n-i+1)*2));
		cout<<ans<<endl;
	}
	return 0;
}