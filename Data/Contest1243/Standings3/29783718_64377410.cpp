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

char s[100005],t[100005];
int p[100005];
int tot=0;
int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n;
		cin>>n;
		cin>>s>>t;
		tot=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]!=t[i])
			p[tot++]=i;
		}
		if (tot>2||tot==1)
		{
			cout<<"No"<<endl;
			continue;
		}
		
		if (tot==0) 
		{
			cout<<"Yes"<<endl;
			continue;
		}
		if (tot==2)
		{
			if (s[p[0]]==s[p[1]]&&t[p[1]]==t[p[0]])
			cout<<"Yes"<<endl;
			else 
			cout<<"No"<<endl;
		}
	}
    return 0;
}

