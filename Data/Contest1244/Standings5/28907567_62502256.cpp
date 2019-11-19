#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,k;
    cin>>n>>k;
    lli a[n],i;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    lli l=0,r=n-1,diff,emj,emj1;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[l]) l=i;
    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==a[r]) r=i;
    }
    while(l<r && k!=0)
    {
        if(l<=n-1-r)
        {
            diff=a[l+1]-a[l];
            if(k-(diff*(l+1))>=0)
            {
                k=k-diff*(l+1);
                l++;
            }
            else
            {
                emj=k/(l+1);
                k=k-emj*(l+1);
                a[l]+=emj;
                break;
            }
        }
        else
        {
            diff=a[r]-a[r-1];
            if(k-(diff*(n-r))>=0)
            {
                k=k-diff*(n-r);
                r--;
            }
            else
            {
                emj=k/(n-r);
                k=k-emj*(n-r);
                a[r]-=emj;
                break;
            }
        }
    }
    if(l>=r) cout<<0;
    else
    {
        cout<<a[r]-a[l];
    }
    return 0;
}