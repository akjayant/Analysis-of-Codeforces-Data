#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
int t;
cin>>t;
int a,b;
while(t--)
{
cin>>a>>b;

if(__gcd(a,b)==1)
cout<<"Finite"<<endl;
else
cout<<"Infinite"<<endl;
}
}
