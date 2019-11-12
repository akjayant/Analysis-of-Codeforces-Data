#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
vector<string> v;
int main()
{
	ios_base::sync_with_stdio(false);
	long long k,i,n;
	string s,t;
	cin>>k;
	while(k--)
	{
		cin>>n>>s>>t;
		if(s==t)
		{
			cout<<"Yes\n";
			continue;
		}
		v.clear();
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				v.push_back("");
				v.back()+=s[i];
				v.back()+=t[i];
			}
		}
		if(v.size()!=2)
		{
			cout<<"No\n";
			continue;
		}
		if(v[0]==v[1])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
