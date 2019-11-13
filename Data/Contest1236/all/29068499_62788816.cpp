#include <bits/stdc++.h>
using namespace std;
long long n,m,mod=1000000007;
long long power(long long a, long long b)
{
    long long tmp1=a;
    long long tmp2=b;
    long long ret=1;
    while(tmp2>0)
    {
        if(tmp2%2==1)
            ret=(ret*tmp1)%mod;
        tmp1=(tmp1*tmp1)%mod;
        tmp2/=2;
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    cout<<power((power(2,m)-1),n);
}
