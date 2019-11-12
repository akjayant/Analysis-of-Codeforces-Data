#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long power(long long x,long long n)
{ 
    long long result = 1; 
    while (n) { 
        if (n & 1) 
            result = result * x % MOD; 
        n = n / 2; 
        x = x * x % MOD; 
    } 
    return result; 
} 
int main()
{
	long long n,m,ans;
	cin>>n>>m;
	ans=(power(2,m)-1)%MOD;
	if(ans<0)
		ans+=MOD;
	ans=power(ans,n);
	cout<<ans;
}