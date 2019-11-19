#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k=0;
int calc(ll n)
{
    int m=0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
        {
            m++;
            k=i;
            while(n%i==0) n/=i;
        }
    if(n>1)
    {m++;
    k=n;
    }
    return m;
}
bool isPrime(ll n)
{
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    ll n;
    while(cin>>n)
    {
    if(isPrime(n)) cout<<n<<endl;
    else if(calc(n)==1) cout<<k<<endl;
    else cout<<1<<endl;
    }
    return 0;
}