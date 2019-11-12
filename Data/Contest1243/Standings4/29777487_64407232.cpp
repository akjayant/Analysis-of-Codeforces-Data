#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define M 1000000007
using namespace std;
const int inf=4e18;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int k;cin>>k;
	while(k--)
	{
		int n;cin>>n;
		string s,t;cin>>s>>t;
		vector<pair<int,int> > v;
		int i,j,o=0;
		bool b=1;
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(t[i]==t[j])
					{
						swap(s[i],t[j]);
						v.pb({i+1,j+1});
						o++;
						break;
					}
				}
				if(j==n)
				{
					for(j=i+1;j<n;j++)
					{
						if(s[j]==t[i])
						{
							swap(s[j],t[j]);
							v.pb({j+1,j+1});
							o++;
							break;
						}
					}
					if(j==n)
					{
						b=0;
						break;
					}
					swap(s[i],t[j]);
					v.pb({i+1,j+1});
					o++;
				}
			}
		}
		if(b)
		{
			cout<<"YES\n"<<o<<'\n';
			for(i=0;i<v.size();i++)
				cout<<v[i].first<<' '<<v[i].second<<'\n';
		}
		else
			cout<<"NO\n";
	}
}
