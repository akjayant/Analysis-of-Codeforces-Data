#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
char s[10005],t[10005];
int num[27];
vector<pii>v;
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int n,f=1;v.clear();
		scanf("%d%s%s",&n,s,t);
		for(int i=0;i<26;i++)num[i]=0;
		for(int i=0;s[i];i++)num[s[i]-'a']++,num[t[i]-'a']++;
		for(int i=0;i<26;i++)if(num[i]&1){f=0;break;}
		if(!f)puts("No");
		else
		{
			for(int i=0;i<n;i++)
			{
				if(t[i]==s[i])continue;
				for(int j=i+1;j<n;j++)
				{
					if(t[j]==s[i]){v.push_back(mp(n-1,j)),v.push_back(mp(n-1,i)),swap(s[n-1],t[j]),swap(s[n-1],t[i]);break;}
					if(s[j]==s[i]){v.push_back(mp(j,i)),swap(s[j],t[i]);break;}
				}
			}
			puts("Yes");
			printf("%d\n",v.size());
			for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first+1,v[i].second+1);
		}
	}
	return 0;
}
