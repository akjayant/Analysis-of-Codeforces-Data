#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(b>a) swap(a,b);
		int x = gcd(a,b);
		if(x!=1) cout<<"infinite\n";
		else cout<<"finite\n";
	} 
	return 0;
}