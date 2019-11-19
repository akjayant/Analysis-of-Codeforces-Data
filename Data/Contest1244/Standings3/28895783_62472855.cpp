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
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll a = n,b = -1;
        forn(i,n) if(s[i]=='1') b=i;
        for(int i=n-1;i>=0;i--) if(s[i]=='1') a = i;

        ll ans = (b+1)*2;
        if((n-a)*2>ans)
          ans = (n-a)*2;

        if(a==n &&  b==-1)
          ans = n;
        cout<<ans<<endl;

    }

}