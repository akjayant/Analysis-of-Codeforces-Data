#include<bits/stdc++.h>
//#include <numeric>
using namespace std;
#define int long long int
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int s=0;
    for(i=0;i<n/2;i++)
        s+=a[i];
    int ans=s*s;
    //4
    //cout<<s<<" ";
    s=0;
    for(i=n/2;i<n;i++)
        s+=a[i];
    ans+=s*s;
    cout<<ans;
}