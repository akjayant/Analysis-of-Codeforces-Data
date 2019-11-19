#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
namespace Dango
{
	const int MAXN=1005;
	string st;
	int t,n;
	void solve()
	{
		cin>>n>>st;
		int ans=n;
		for(int i=0;i<st.length();i++)
			if(st[i]=='1')
				ans=max(ans,max((i+1)*2,(n-i)*2));
		cout<<ans<<endl;
	}
	int work()
	{
		ios::sync_with_stdio(false);
		cin>>t;
		for(int i=1;i<=t;i++)
			solve();
		return 0;
	}
}
int main()
{
	return Dango::work();
}