#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int mod=1e9+7;
int power(int x,int y,int p)
{ 
    int res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
        if((y & 1)==1) 
            res = (res * x) % p; 
        y = y >> 1;  
        x = (x * x) % p;  
    } 
    return res; 
} 
int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    //(2^0 +2^1 .. 2^(m-1))
    int pow=power(2,m,mod)-1;
    int ans=power(pow,n,mod);
    cout<<ans;
}