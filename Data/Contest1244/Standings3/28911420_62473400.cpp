#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int mx=n;
		string s;
		cin>>s;
		for (int i = 0; i < n; ++i)
		{
			if (s[i]=='1')
			{
				mx=max(mx,2*(n-i));
				break;
			}
		}
		for (int i = n-1; i > -1; --i)
		{
			if (s[i]=='1')
			{
				mx=max(mx,2*(i+1));
				break;
			}
		}
		cout<<mx<<endl;
	}
}