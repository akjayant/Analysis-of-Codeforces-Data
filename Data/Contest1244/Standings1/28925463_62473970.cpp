#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    for(long long i=0;i<=c;i++)
    {
        if((b-i*d)%c)continue;
        long long j=(b-i*d)/c,q=a-i-j;
        if(j<0 || q<0)continue;
        printf("%lld %lld %lld\n",j,i,q);
        return 0;
    }
    puts("-1");
    return 0;
}