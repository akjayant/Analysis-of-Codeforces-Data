#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll t,n;
string s1,s2;
vector<int>pos;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s1>>s2;
		pos.clear();
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]!=s2[i])
			pos.push_back(i);
		}
		if(pos.size()!=2)
		{
			cout<<"No\n";
			continue;
		}
		else
		{
			if(!(s1[pos[0]]==s1[pos[1]]&&s2[pos[0]]==s2[pos[1]]))
			{
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
		}
	}
	return 0;
}