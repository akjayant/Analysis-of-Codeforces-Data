#include<bits/stdc++.h>
using namespace std;
char s[100001];
char c[100001];
signed main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		cin>>s+1;
		cin>>c+1;
		vector<pair<int,int> >rem;
		for(int i=1;i<=n;i++)
			if(s[i]!=c[i])
			{
				int flag=0;
				for(int j=i;j<=n;j++)
					if(s[i]==c[j])
					{
						rem.push_back(make_pair(n,j));
						swap(s[n],c[j]);
						rem.push_back(make_pair(n,i));
						swap(s[n],c[i]);
						flag=1;
						break;
					}
				for(int j=i+1;j<=n;j++)
					if(s[i]==s[j]&&!flag)
					{
						rem.push_back(make_pair(j,i));
						swap(s[j],c[i]);
						flag=1;
						break;
					}
			}
		int flag=0;
		for(int i=1;i<=n;i++)
			if(s[i]!=c[i])
				flag=1;
		if(flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			printf("%d\n",rem.size());
			for(int i=0;i<rem.size();i++)
				printf("%d %d\n",rem[i].first,rem[i].second);
		}
	}
	return 0;
}
