#include<bits/stdc++.h>
using namespace std;
string s;
int pos[1005],k=0;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		k=0;
		int n;
		scanf("%d",&n);
		cin>>s;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]=='1')pos[++k]=i+1;
		}
		if(!k)
		{
			printf("%d\n",n);
			continue;
		}
		int ans=n+k;
		ans=max(ans,2*pos[k]);
		ans=max(ans,2*(n-pos[1]+1));
		printf("%d\n",ans);
	}
	return 0;
}