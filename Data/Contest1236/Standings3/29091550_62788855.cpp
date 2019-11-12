#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int a1=min(b,c/2);
		b-=a1;
		c-=2*a1;
		int a2=min(a,b/2);
		cout<<3*(a1+a2)<<endl;
	}
	return 0;
}