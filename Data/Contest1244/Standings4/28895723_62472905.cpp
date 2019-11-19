#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define M 1000000007
#define N 1000016
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define inf 9000000000000000000


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   ll t;
   cin>>t;
   while(t--) {

        ll n;
        string s;
        cin>>n>>s;
        ll l=-1, r=-1;
        for(ll i=0; i<s.size(); i++) {
            if(s[i]=='1') {
                if(l==-1)
                    l = i;
                r = i;
            }
        }

        if(l==-1)
            cout<<n<<"\n";
        else {
            ll ans = max(n+1, max(2*(r+1), 2*(n-l)));
            cout<<ans<<"\n";
        }

   }


    return 0;
}
