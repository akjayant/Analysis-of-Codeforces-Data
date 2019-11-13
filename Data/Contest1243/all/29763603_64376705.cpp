/*
सत्यान्न प्रमदितव्यम्  || 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mx 1000005
#define mod 1000000007
// #define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define mxi 2005

int main()
{
    fast_as_levi;
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,n;
        cin>>n;
        ll ar[n];
        for(i=0;i<n;i++)cin>>ar[i];
        sort(ar,ar+n);
        ll ans = INT_MIN;
        for(i=0;i<n;i++)
        {
            if(ar[i]>=n-i)
            ans = max(ans,n-i);
        }
        cout<<ans<<"\n";
    }
}