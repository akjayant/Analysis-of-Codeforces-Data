#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int power(long long int x,long long int y,long long int p) 
{ 
    long long int res = 1;
    x=x%p;  
    while (y>0) 
    { 
        if (y&1) 
            res = (res*x) % p; 
       
        y=y>>1; 
        x=(x*x)%p;   
    } 
    return res; 
}
int main()
{
	long long int a,b;
	cin>>a>>b;
	cout<<power(power(2,b,mod)-1,a,mod)<<"\n";
}