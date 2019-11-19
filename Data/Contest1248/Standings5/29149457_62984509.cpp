#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll i,j,k;
    vector<ll> arr(n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll posx=0,posy=0;
    k=n-1;
    for(i=0;i<k;i++)
    {
        posx+=arr[k];
        posy+=arr[i];
        k--;
    }
    if(i==k)
        posx+=arr[i];
    ll ans=posx*posx;
    ans+=posy*posy;
    cout<<ans<<endl;
    return 0;
}