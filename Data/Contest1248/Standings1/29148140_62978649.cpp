//A. Integer Points
//By: Terrasse
//2019年 10月 20日 星期日 17:07:10 CST

#include<iostream>
#define int long long
using namespace std;
signed main()
{
    register int a[2]={0,0},c[2]={0,0},i=0,b=0,t=0,n=0,m=0;
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    for(;t--;)
    {
        cin>>n;a[0]=a[1]=0;c[0]=c[1]=0;
        for(i=1;i<=n;++i)
        {
            cin>>b;
            ++a[b&1];
        }
        cin>>m;
        for(i=1;i<=m;++i)
        {
            cin>>b;
            ++c[b&1];
        }
        cout<<a[0]*c[0]+a[1]*c[1]<<endl;
    }
    return 0;
}
