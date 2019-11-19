#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int t,a,b,c,d,k;
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>k;
		int x=(a-1)/c+1,y=(b-1)/d+1;
		if(x+y>k)
			cout<<-1<<endl;
		else
			cout<<x<<" "<<y<<endl;
	}
	return 0;
}