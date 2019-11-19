#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],b[5],ans,x,m,t;
int main() 
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        b[0]=0; b[1]=0;
        ans=0;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            b[a[i]%2]++;
        }
        cin>>m;
        for (int i=0; i<m; i++)
        {
            cin>>x;
            ans+=b[x%2];
        }
        cout<<ans<<endl;
    }
    return 0;
}