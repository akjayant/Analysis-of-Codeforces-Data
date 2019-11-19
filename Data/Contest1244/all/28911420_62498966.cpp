#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,p,w,d,x,y,t;
	cin>>n>>p>>w>>d;
	t=p;
	x=p/w;
	p=p%w;
	//cout<<p<<endl;
	if (p%d>0)
	{
		for (int i = 1; i < d; ++i)
		{
			p+=w;
			if (p%d==0)
			{
				x-=i;
				break;
			}
		}
	}
	if (p%d>0 || x<0 || w<=d || p>t)
	{
		cout<<-1<<endl;
	}
	else
	{
		y=p/d;
		if (x+y<=n)
		{
			cout<<x<<" "<<y<<" "<<n-x-y<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}