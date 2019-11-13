#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
     {
	 cin>>n>>m;
	 if(gcd(n,m)==1)cout<<"Finite"<<endl;else cout<<"Infinite"<<endl;
     }
	return 0;
}