#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<iomanip>
using namespace std;

vector<int> v;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int ouo;
	cin>>ouo;
	while(ouo--)
	{
		string s,t;
		int i,n;
		cin>>n;
		cin>>s>>t;
		v.clear();
		
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				v.emplace_back(i);
			}
		}
		
		if(v.size()>2 || v.size()==1)
			cout<<"No\n";
		else if(v.size()==0)
			cout<<"Yes\n";
		else if(s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	
	
	return 0;
}
