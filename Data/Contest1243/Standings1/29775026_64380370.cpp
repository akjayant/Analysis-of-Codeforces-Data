#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		string s1,s2;
		int n,x=0,y=0,cnt=0;
		cin>>n>>s1>>s2;
		rep(i,0,n-1)
		{
			if (s1[i]!=s2[i])
			{
				cnt++;
				if (cnt==3)
				{
					cout<<"No"<<endl;
					break;
				}
				if (x==y)
				{
					x=i;
				}
				else
				{
					y=i;
				}
			}
		}
		if (cnt==3)
		{
			continue;
		}
		if (cnt==1)
		{
			cout<<"No"<<endl;
			continue;
		}
		else
		{
			if (s1[x]==s1[y] && s2[y]==s2[x])
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
