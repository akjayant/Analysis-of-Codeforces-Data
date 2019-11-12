#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ll ans=0,hh=0;
        sort(a,a+n);
        for(ll i=n-1;i>=0;i--){
            if(ans<(min(n-i,a[i])*min(n-i,a[i]))){
                ans=(min(n-i,a[i])*min(n-i,a[i]));
                hh=n-i;
            }
        }
        cout<<hh<<endl;
    }
}
