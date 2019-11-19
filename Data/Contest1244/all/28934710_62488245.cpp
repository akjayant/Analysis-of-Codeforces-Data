#include <bits/stdc++.h>
#define DIM 100007
#define INF 1000000000000000007LL
using namespace std;

long long n,k,a[DIM],p[DIM];

bool F(long long d)
{
    //long long a2 = d;
    //int ps = upper_bound(a,a+1+n,a2)-a;
    // cout<<a1<<' '<<a2<<' '<<ps<<endl;
    //long long curr = (p[n]-p[ps-1]) - (n-ps+1)*a2;
    //if(curr<=k) return 1;
    for(int i = 1; i <= n; ++i)
    {
        long long a1 = a[i];
        long long a2 = a[i]+d;
        int ps = upper_bound(a,a+1+n,a2)-a;
       // cout<<a1<<' '<<a2<<' '<<ps<<endl;
        long long curr = (i-1)*a1 - p[i-1] + (p[n]-p[ps-1]) - (n-ps+1)*a2;
        if(curr<=k) return 1;
    }
    for(int i = n; i >= 1; --i)
    {
        long long a2 = a[i];
        long long a1 = a[i]-d;
        int ps = lower_bound(a,a+1+n,a1)-a-1;
        long long curr = 0;
        if(ps>0) curr+=ps*a1-p[ps];
        curr+=p[n]-p[i]-(n-i)*a2;
        if(curr<=k) return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];

    sort(a+1,a+1+n);
    for(int i =1; i <= n; ++i)
        p[i] = p[i-1]+a[i];
    a[n+1]=INF;
    long long l = 0, r = a[n],m;
    while(l<r)
    {
        m = (l+r)/2;
        if(F(m)) r = m;else l = m+1;
    }
    cout<<l;


    return 0;
}
