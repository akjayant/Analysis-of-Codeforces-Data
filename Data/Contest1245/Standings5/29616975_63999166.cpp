//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int t,a,b,c,n;
string s,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		ans="";
		cin>>n>>a>>b>>c>>s;
		int win=0;
		for(int i=0;i<n;i++)
		{
			ans+=' ';
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R' && b)
			{
				b--;
				ans[i]='P';
				win++;
			}
			else if(s[i]=='P' && c)
			{
				c--;
				ans[i]='S';
				win++;
			}
			else if(s[i]=='S' && a)
			{
				a--;
				ans[i]='R';
				win++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(ans[i]==' ')
			{
				if(a)
				{
					ans[i]='R';
					a--;
				}
				else if(b)
				{
					ans[i]='P';
					b--;
				}
				else
				{
					ans[i]='S';
					c--;
				}
			}
		}
		if(win>=(n/2+n%2))
		{
			cout<<"YES"<<endl<<ans<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}