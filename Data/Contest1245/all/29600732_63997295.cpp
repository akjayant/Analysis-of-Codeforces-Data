#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		if(__gcd(a,b)==1)
			puts("Finite");
		else
			puts("Infinite");
	} 
	return 0;
}