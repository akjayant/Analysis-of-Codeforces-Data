#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
#define INF 0x7f7f7f7f

using namespace std;

int main()
{
    ll n,a[100005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n/2;i++)
    {
        sum1+=a[i];
    }
    for(int i=n/2+1;i<=n;i++)
    {
        sum2+=a[i];
    }
    cout<<sum1*sum1+sum2*sum2<<endl;
    return 0;
}
