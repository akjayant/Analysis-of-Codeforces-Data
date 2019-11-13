#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,h[266];
char s[55],t[55];
vector<pair<int,int>>ans;
int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		for(int i='a';i<='z';i++)h[i]=0;
		ans.clear();
		scanf("%d%s%s",&n,s,t);
		for(int i=0;i<n;i++)
			h[s[i]]++,h[t[i]]++;
		for(int i='a';i<='z';i++)
			if(h[i]&1)
			{puts("no");goto ok;}
		puts("yes");
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
			{
				for(int j=i+1;j<n;j++)
					if(s[i]==s[j])
					{swap(s[j],t[i]),ans.emplace_back(j,i);goto x;}
				for(int j=i+1;j<n;j++)
					if(s[i]==t[j])
					{
						swap(s[j],t[j]),ans.emplace_back(j,j);
						swap(s[j],t[i]),ans.emplace_back(j,i);
						break;
					}
				x:;
			}
		printf("%u\n",ans.size());
		for(auto p:ans)
			printf("%d %d\n",p.first+1,p.second+1);
		ok:;
	}
	return 0;
}