#include <iostream>
#define mod 1000000007;
using namespace std;
long long int n,m,a;
void logpow(long long int &baza,long long int exp)
{
    long long int res=1,aux=baza;
    while(exp)
    {
        if(exp%2==1)
            res*=aux;
        res%=mod;
        exp/=2;
        aux*=aux;
        aux%=mod;
    }
    baza=res;
}
int main()
{
    cin>>n>>m;
    a=2;
    logpow(a,m);
    a+=mod;
    a--;
    a%=mod;
    logpow(a,n);
    cout<<a;
    return 0;
}
