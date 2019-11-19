#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009],k;
int n;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll b=a[0],cb=1,e=a[n-1],ce=1,bi=0,ei=n-1;
    while(b!=e&&k>0&&ei>0&&bi<n-1)
    {
        bool o=0;
        while(b==a[bi+1])
        {
            bi++;
            cb++;
            if(bi==ei)
            {
                o=1;
                break;
            }
        }
        if(o)break;
        while(e==a[ei-1])
        {
            ei--;
            ce++;
            if(ei==bi)
            {
                o=1;
                break;
            }
        }
        if(o)break;
        if(cb>ce)
        {
            ll ex=(e-a[ei-1])*ce;
            ex=min(ex,k);
            k-=ex;
            e-=ex/ce;
        }
        else
        {
            ll ex=(a[bi+1]-b)*cb;
            ex=min(ex,k);
            k-=ex;
            b+=ex/cb;
        }
    }
    cout<<e-b;
}
