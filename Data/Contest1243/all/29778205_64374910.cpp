#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
int k,a[1005],res,n;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
   // freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>k;
    while(k--)
    {
        int d;
        res=INT_MIN;
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--)
        {
            res=max(res,min(n-i+1,a[i]));
        }
        cout<<res<<endl;
    }
}
