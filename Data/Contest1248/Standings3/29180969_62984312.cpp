#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    ll x=0,y=0;
    for(int i=1;i<=n/2;i++)
    {
        x+=a[i];
    }
    for(int i=n/2+1;i<=n;i++)
    {
        y+=a[i];
    }
    printf("%I64d\n",x*x+y*y);
    return 0;
}