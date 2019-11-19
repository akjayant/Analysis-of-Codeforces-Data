#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl;
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--) {
        ll n,k,i,j,m;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        for(i=0;i<n;i++) {
            a[i]=b[i]=i+1;
        }
        j=n*(n+1);
        j=j/2;
        if(j>k) {
            cout<<"-1";
        } else {
            ll l=1,r=n;
            while(l<r && j<k) {
                ll x = k-j;
                ll z;
                if((r-l)<x) {
                    z = l;
                } else {
                    z = r-x;
                }
                ll g = b[r-1];
                b[r-1]=b[z-1];
                b[z-1]=g;
                j+=(r-z);
                r--;
                l++;
            }
            cout<<j<<endl;
            for(i=0;i<n;i++) 
                cout<<a[i]<<" ";
            cout<<endl;
            for(i=0;i<n;i++)
                cout<<b[i]<<" ";
        }
    }
    return 0;
}