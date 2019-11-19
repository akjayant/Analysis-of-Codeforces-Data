//B. Grow The Tree
//By: Terrasse
//2019年 10月 20日 星期日 17:17:24 CST

#include<iostream>
#include<algorithm>
#define int long long
#define MAXN 100011
using namespace std;
int a[MAXN];
signed main()
{
    register int i=0,n=0,m=0,x=0,y=0;
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);reverse(a+1,a+n+1);m=(n+1)/2;
    for(i=1;i<=m;++i)
    {
        x+=a[i];
    }
    for(;i<=n;++i)
    {
        y+=a[i];
    }
    cout<<x*x+y*y<<endl;
    return 0;
}
