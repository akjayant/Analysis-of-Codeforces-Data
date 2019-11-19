#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll x=0,y=0;
    for(int i=0;i<n/2;i++)
    {
        x = x + a[i];
        y = y + a[n-i-1];
    }
    if(n%2==1)y+=a[n/2];
    ll ans = x*x + y*y;
    cout<<ans<<endl;
    return 0;
}