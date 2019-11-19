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
    ll t,a[100005],n,m;
    cin>>t;
    while(t--)
    {
        ll jishu1=0,jishu2=0,oushu1=0,oushu2=0;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2)
                jishu1++;
            else
                oushu1++;
        }
        cin>>m;
        for(ll i=0;i<m;i++)
        {
            cin>>a[i];
            if(a[i]%2)
                jishu2++;
            else
                oushu2++;
        }
        cout<<jishu1*jishu2+oushu1*oushu2<<endl;
    }
    return 0;
}
