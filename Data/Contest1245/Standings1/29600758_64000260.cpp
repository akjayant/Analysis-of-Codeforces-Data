#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
typedef pair<int,int> pii;
set<int> se;
vector<int> vec;
queue<int> q;
int vis[maxn];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int a,b,c,a1=0,b1=0,c1=0;cin>>a>>b>>c;
		string s;cin>>s;memset(vis,0,sizeof vis);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='R') a1++;
			if(s[i]=='P') b1++;
			if(s[i]=='S') c1++;
		}
		int ans=min(a1,b)+min(b1,c)+min(c1,a);
		string s1=s;
		if(ans>=(n+1)/2)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='R'&&b>0) vis[i]=1,b--,s1[i]='P';
				else if(s[i]=='P'&&c>0) vis[i]=1,c--,s1[i]='S';
				else if(s[i]=='S'&&a>0) vis[i]=1,a--,s1[i]='R';
			}
			for(int i=0;i<n;i++)
			{
				if(!vis[i])
				{
					if(a>0) a--,s1[i]='R';
					else if(b>0) b--,s1[i]='P';
					else if(c>0) c--,s1[i]='S';
				}
			}
			cout<<s1<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
 } 