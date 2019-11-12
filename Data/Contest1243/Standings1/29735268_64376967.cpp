#include<bits/stdc++.h>
using namespace std;
char s[100001];
char c[100001];
signed main() 
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		cin>>s+1;
		cin>>c+1;
		vector<int>v;
		for(int i=1;i<=n;i++)
			if(s[i]!=c[i])
				v.push_back(i);
		if(v.size()==0)
		{
			printf("YES\n");
		}
		else if(v.size()==2)
		{
			if(s[v[0]]==s[v[1]]&&c[v[1]]==c[v[0]])
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
