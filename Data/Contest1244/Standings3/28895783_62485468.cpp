#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define fast ios_base::sync_with_stdio(false);     cin.tie(NULL);
#define ll  long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define pa pair<long long int,long long int>
#define forn(i,n) for(int i=0;i<n;i++)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;


int main(){

  int t=1;
    //cin>>t;
    while(t--)
    {
      ll n,k;
      cin>>n>>k;
      ll a[n];
      forn(i,n) a[i] = i+1;

      ll ans = 0;
      forn(i,n) ans+=a[i];

      //cout<<ans<<endl;

      if(ans>k)
        cout<<"-1\n";

      else
      {
        ll i=0;
        while(ans<k  &&  i<n/2){
          if((a[n-i-1]-a[i])<=(k-ans))
          {
            ans+=a[n-i-1]-a[i];
            ll temp = a[i];
            a[i] = a[n-i-1];
            a[n-i-1] = temp;
          }
          else{
            ll oo = k-ans;
            if(i+oo>(n-i-1))
              oo = (n-i-1) - i;
            ans+=oo;
            ll temp = a[i];
            a[i] = a[i+oo];
            a[i+oo] = temp;
          }
          i++;
        }
        cout<<ans<<endl;
        forn(i,n) cout<<i+1<<" ";
        cout<<endl;
        forn(i,n) cout<<a[i]<<" ";
        cout<<endl;
      }

      // ll a,b,c,d;
      // cin>>a>>b>>c>>d;
      // if(a*c<b)
      //   cout<<"-1\n";
      // else
      // {
      //   if()
      // }
        // ll n,k;
        // cin>>n>>k;
        // ll a[n];
        // forn(i,n) cin>>a[i];

        // sort(a,a+n);

        // map<ll,ll> m;


    }

}