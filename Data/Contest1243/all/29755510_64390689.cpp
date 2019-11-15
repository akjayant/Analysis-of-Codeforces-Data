#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> pll;
vector<pll> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	long long k,i,n,j;
	bool flag;
	string s,t;
	cin>>k;
	while(k--)
	{
		ans.clear();
		flag=true;
		cin>>n>>s>>t;
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(t[j]==t[i])
					{
						swap(s[i],t[j]);
						ans.push_back(pll(i,j));
						break;
					}
				}
			}
			if(s[i]!=t[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(s[j]==t[i])
					{
						swap(s[j],t[j]);
						ans.push_back(pll(j,j));
						swap(s[i],t[j]);
						ans.push_back(pll(i,j));
						break;
					}
				}
			}
			if(s[i]!=t[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"Yes\n"<<ans.size()<<"\n";
			for(i=0;i<ans.size();i++)
				cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
		}
		else
			cout<<"No\n";
	}
	return 0;
}
