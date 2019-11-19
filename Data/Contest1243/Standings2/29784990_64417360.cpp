#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<set>
#define int long long
using namespace std;

set<pair<int,int> > s;
set<int> v;
queue<int> q;

signed main() {
	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	int n,m;
	int a,b,i;
	
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
		v.insert(i);
	}
	
	while(m--)
	{
		cin>>a>>b;
		s.insert(make_pair(a,b));
		s.insert(make_pair(b,a));
	}
	int ans=-1;
	for(i=1;i<=n;i++)
	{
		if(v.find(i)!=v.end())
		{
			ans++;
			q.push(i);
			v.erase(i);
			
			while(!q.empty())
			{
				a=q.front();
//				cout<<a<<'\n';
				
				vector<int> aoi;
				aoi.clear();
				
				for(auto ouo:v)
				{
					if(s.find(make_pair(a,ouo))==s.end())
					{
						q.push(ouo);
						aoi.emplace_back(ouo);
					}
				}
				for(int sana:aoi)
				{
					v.erase(sana);
				}
				
				q.pop();
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}

