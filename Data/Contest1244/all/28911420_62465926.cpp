#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=a/c,y=b/d;
		if (a%c)
		{
			x++;
		}
		if (b%d)
		{
			y++;
		}
		if (x+y<=k)
		{
			cout<<x<<" "<<y<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}