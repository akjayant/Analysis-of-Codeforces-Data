#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int a1=(a-1)/c+1,a2=(b-1)/d+1;
		if(a1+a2>k)
			cout<<-1<<endl;
		else
			cout<<a1<<' '<<a2<<endl;
	}
}