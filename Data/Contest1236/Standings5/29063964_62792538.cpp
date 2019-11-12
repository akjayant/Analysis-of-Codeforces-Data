#include<bits/stdc++.h> 
using namespace std;

long long int power(long long int x, long long int y, int p) 
{ 
    long long int res = 1;   
  
    x = x % p; 
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int i,j,n,m;
    cin>>n>>m;
    int mod=1000000007;
    long long int pow1=power(2,m,mod);
    pow1=(pow1-1)%mod;
    long long int pow2=power(pow1,n,mod);

    cout<<pow2<<endl;


}