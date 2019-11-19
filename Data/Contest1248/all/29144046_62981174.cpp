#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[100050];
ll x,y;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r)
    {
        x+=a[r];
        if(r>l)y+=a[l];
        l++;
        r--;
    }
    printf("%lld\n",x*x+y*y);
    return 0;
}
