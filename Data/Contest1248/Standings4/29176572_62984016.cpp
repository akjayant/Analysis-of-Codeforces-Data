#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    //cin>>t;
   // while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        
        ll h=0;
        ll v=0;
        int j=n-1;
        for(int i=0;i<=j;i++,j--)
        {
            h=h+a[i];
            if(i==j)
                break;
            v=v+a[j];
        }
        
        cout<<h*h+v*v<<endl;
        
    }
    return 0;
}
