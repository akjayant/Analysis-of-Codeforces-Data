#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<iomanip>
using namespace std;

vector<int> a,b;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int ouo;
	cin>>ouo;
	while(ouo--)
	{
		string s,t,ouo,qwq;
		int i,n,j;
		cin>>n;
		cin>>s>>t;
		
		int cnt[256]={0};
		for(char ch:s)
			cnt[ch]++;
		for(char ch:t)
			cnt[ch]++;
		
		bool flag=0;
		for(int ouo:cnt)
		{
			if(ouo&1)
			{
				cout<<"No\n";
				flag=1;
				break;
			}
		}
		if(flag)
			continue;
		
		a.clear();
		b.clear();
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				for(j=i+1;j<n;j++)
				{
					if(t[i]==t[j])
					{
						a.emplace_back(i);
						b.emplace_back(j);
						swap(s[i],t[j]);
						break;
					}
					else if(t[i]==s[j])
					{
						a.emplace_back(j);
						b.emplace_back(j);
						swap(s[j],t[j]);
						a.emplace_back(i);
						b.emplace_back(j);
						swap(s[i],t[j]);
						break;
					}
				}
			}
		}
		cout<<"Yes\n";
		cout<<a.size()<<'\n';
		for(i=0;i<a.size();i++)
		{
			cout<<a[i]+1<<' '<<b[i]+1<<'\n';
		}
	}
	
	
	return 0;
}
