#include<bits/stdc++.h>
using namespace std;
const int mn=1e3+6;
int test,n;
int a[mn];
bool cmp(int a,int b)
{
    return a>b;
}
int res=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>test;
    while(test--)
    {
        res=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)res=max(res,min(a[i],i));
        cout<<res<<'\n';
    }
    return 0;
}
