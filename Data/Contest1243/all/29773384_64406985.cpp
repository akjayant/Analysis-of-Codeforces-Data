#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

map< pair<int , int> , bool>mp ;
int erased[MAX] ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m;
	cin>>n>>m ;
	for(int i = 0 ; i < m ; ++i)
	{
		int x , y ;
		cin>>x>>y ;
		mp[{min(x , y) , max(x , y)}] = 1 ;
	}
	set<int>s ;
	for(int i = 1 ; i <= n ; ++i)
		s.insert(i) ;
	queue<int>q ;
	int ans = 0 ;
	vector<int>v ;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(erased[i])
			continue ;
		if(i > 1)
			ans++ ;
		q.push(i) ;
		erased[i] = 1 ;
		s.erase(i) ;
		while(!q.empty())
		{
			int node = q.front() ;
			q.pop() ;
			int last = v.size() ;
			for(auto &cur : s)
			{
				if(mp[{min(node , cur) , max(node , cur)}] == 0)
				{
					q.push(cur) ;
					v.push_back(cur) ;
				}
			}
			for(int j = last ; j < v.size() ; ++j)
				s.erase(v[j]) , erased[v[j]] = 1 ;
		}
	}
	return cout<<ans<<"\n" , 0 ;
}