#include <iostream>

using namespace std;

int main()
{
    long long n,k,flag=0;
    cin>>n;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            k=i;
            break;
        }
    }
    if(flag==0)
    {
        cout<<n;
        return 0;
    }
    while(n>1)
    {
        if(n%k)
        {
            flag=2;
            break;
        }
        n/=k;
    }
    if(flag==2) cout<<"1";
    else cout<<k;
    return 0;
}
