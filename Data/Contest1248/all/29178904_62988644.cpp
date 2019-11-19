#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i =0 ;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }    
    sort(a,a+n);
    ll x =0 ,y =0 ;
    for(int i = 0;i<(n)/2;i++)
    {
        x += a[i];
    }
    // cout<<" x = "<<x<<endl;
    for(int i = (n)/2;i<n;i++)
    {
        y += a[i];
    }
    printf("%lld\n",x * x + y * y);
}