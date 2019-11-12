#include <bits/stdc++.h>

using namespace std;
string a;
string b;
int cnt[27];

vector < pair < int , int > > v;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		int n;
		cin>>n;
		cin>>a>>b;
		bool q=0;
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<n;i++)
			cnt[a[i]-'a']++;
		for(int i=0;i<n;i++)
			cnt[b[i]-'a']++;
		for(int i=0;i<27;i++)
		if(cnt[i]%2)
		{
			
			q=1;
			break;
		}
		if(q)
		{	
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n"<<endl;
		int m=n*2;
		int ans=0;
		while(m--)
		{
			q=0;
			for(int i=0;i<n&&!q;i++)
			{
				for(int j=i+1;j<n&&!q;j++)
				{
					if(a[i]!=b[i]&&a[i]==a[j]&&a[i]!=b[j])
					{
						ans++;
						v.push_back({i+1,j+1});
						swap(a[i],b[j]);
						q=1;
					}
				}
			}
			if(!q)
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]!=b[i])
					{
						ans++;
						v.push_back({i+1,i+1});
						swap(a[i],b[i]);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(auto x:v)
		cout<<x.first<<' '<<x.second<<endl;
	}
	
	
	
	
	return 0;
}
