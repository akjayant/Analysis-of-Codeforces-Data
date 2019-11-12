#include<bits/stdc++.h>
#define MODULO 1000000007
using namespace std;
long long pw(long long x,long long p){
    if(p==1)
        return x;
    else{
        long long aux=pw(x,p/2);
        if(p%2==0)
            return (aux*aux)%MODULO;
        else
            return (((aux*aux)%MODULO)*x)%MODULO;
    }
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<pw(pw(2,b)-1,a);
    return 0;
}
