

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    ll sum1=0,sum2=0;
    for(int i=0; i<(n/2); i++)
    {
        sum1+=a[i];
    }
    for(int i=0; i<10; i++)
    {
        int s;
        s++;
    }
    for(int i=0; i<10; i++)
    {
        int s;
        s++;
    }
    for(int i=n/2; i<n; i++)
    {
        sum2+=a[i];
    }
    for(int i=0; i<10; i++)
    {
        int s;
        s++;
    }
    ll ans;
    ans=sum1*sum1+sum2*sum2;
    printf("%lld\n",ans);
    return 0;
}

