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

        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll x = a/c;
        if(a%c)
            x++;
        ll y = b/d;
        if(b%d)
            y++;
        if(x+y<=k)
            cout<<x<<" "<<y<<"\n";
        else
            cout<<"-1\n";
   }


    return 0;
}
