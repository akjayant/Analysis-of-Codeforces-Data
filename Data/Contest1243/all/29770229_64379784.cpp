#include <bits/stdc++.h>

using namespace std;
string a;
string b;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>a>>b;
		int x=-1,y=-1,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				cnt++;
				if(x!=-1)
					y=i;
				else
					x=i;
			}
		}
		if(cnt==2&&a[x]==a[y]&&b[y]==b[x])
		cout<<"Yes\n";
		else if(cnt==0)
		cout<<"Yes\n";
		else
		cout<<"No\n";
					
	}
	
	
	
	
	return 0;
}
