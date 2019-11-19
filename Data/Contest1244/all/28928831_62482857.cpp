#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,p,w,d,x,y,z;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p>>w>>d;
	for(y=0;y<=999999;y++)
	{
		long long e=p-y*d;
		if(e%w!=0)
			continue;
		x=e/w;
		z=n-x-y;
		if(x<0||y<0||z<0)
			continue;
		cout<<x<<" "<<y<<" "<<z<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}