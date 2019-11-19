#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,i;
    cin>>n;
    if(n%2==0)
    {
        while(n%2==0)
            n/=2;
        if(n>1)
            cout<<1;
        else
            cout<<2;
        return 0;
    }
    for(i=3;i*i<=n;i+=2)
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            if(n>1)
                cout<<1;
            else
                cout<<i;
            return 0;
        }
    cout<<n;
    return 0;
}