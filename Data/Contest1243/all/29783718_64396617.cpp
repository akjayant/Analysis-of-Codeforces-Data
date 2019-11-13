#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#define inf 0x3f3f3f3f
#define PI acos(-1)
#define eps 1e-6
using namespace std;
typedef long long ll;

char s[100],t[100];
int cnt[30];
int op[105][2];
int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n;
		cin>>n;
		cin>>s>>t;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++)
		{
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		int flag=0;
		for (int i=0;i<26;i++)
		{
			if (cnt[i]%2)
			{
				flag=1;
			}
		}
		if (flag)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		int tot=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]==t[i]) continue;
			int x=0;
			for (int j=i+1;j<n;j++)
			{
				if (s[i]==s[j])
				{
					swap(s[j],t[i]);
					op[tot][0]=j+1;
					op[tot++][1]=i+1;
					x=1;
					break;
				}
				if (t[i]==t[j])
				{
					swap(t[j],s[i]);
					op[tot][0]=i+1;
					op[tot++][1]=j+1;
					x=1;
					break;
				}
			}
			if (x) continue;
			for (int j=i+1;j<n;j++)
			{
				for (int k=i+1;k<n;k++)
				{
					if (s[j]==t[k])
					{
						swap(s[j],t[i]);
						swap(t[k],s[i]);
						op[tot][0]=j+1;
						op[tot++][1]=i+1;
						op[tot][0]=i+1;
						op[tot++][1]=k+1;
						x=1;
					}
					if (x) break;
				}
				if (x) break; 
			}
			if (x) continue;
			swap(s[i],t[i]);
			op[tot][0]=i+1;
			op[tot++][1]=i+1;
			i--;
		}
		cout<<tot<<endl;
		for (int i=0;i<tot;i++)
		{
			cout<<op[i][0]<<" "<<op[i][1]<<endl;
		}
	}
    return 0;
}

