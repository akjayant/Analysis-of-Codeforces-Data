#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int main()
{
    int n;
    ll ans=0;
    ll sum=0;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i< n ;++i)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        a[i]=x;
    }
    sort(a.begin(),a.end());
    ll  oo=0;
    int top=n/2;
    for(int i=0;i<top;++i)
    {
        oo+=a[i];
    }
    sum-=oo;
    ans=oo*oo+sum*sum;
    printf("%lld\n",ans);
    return 0;
}
