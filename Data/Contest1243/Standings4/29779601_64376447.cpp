#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
char s[10005],t[10005];
int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%s%s",&n,s,t);
		int c=0;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
				++c;
		if(c==0)
			puts("yes");
		else if(c==1||c>2)
			puts("no");
		else
		{
			vector<int>v;
			for(int i=0;i<n;i++)
				if(s[i]!=t[i])
					v.push_back(i);
			swap(s[v[0]],t[v[1]]);
			puts(strcmp(s,t)?"no":"yes");
		}
	}
	return 0;
}