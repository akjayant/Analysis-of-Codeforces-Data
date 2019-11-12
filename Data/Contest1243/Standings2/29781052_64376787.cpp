#include <bits/stdc++.h>
#define mn 1005
using namespace std;
int n,k;
int a[mn];
int main()
{
    cin>>k;
    while(k--)
    {
        int res=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i+1;j++)
                if(a[j]>=i)
            {
                res=i;
                break;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
