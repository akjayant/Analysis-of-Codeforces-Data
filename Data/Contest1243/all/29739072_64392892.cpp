//
#include <bits/stdc++.h>
#define mod 1000000007
#define inf 1000000000000000000
#define mk make_pair
#define pb push_back
#define pii pair<lli, lli>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef unsigned long long ull;
typedef long long int lli;
typedef long double ld;
const lli sz=100010, sz2=1000010;
lli toint(const string &s) {stringstream ss; ss << s; lli x; ss >> x; return x;}
string tostring ( lli number ){stringstream ss; ss<< number; return ss.str();}
int main ()
{
    lli n;
    cin>>n;
    vector<lli> v;
    lli m=n;
    for (lli i=2; i*i<=n; i++) {
        if (n%i==0) {
            v.pb(i);
            while (n%i==0 && n>1) {
                n/=i;
            }
        }
    }
    if (n>1) {
        v.pb(n);
    }
    lli ans;
    if (v.size()==1) {
        if (v[0]==n) {
            ans=n;
        }
        else {
            ans=v[0];
        }
    }
    else {
        ans=1;
    }
    cout<<ans<<endl;
    return 0;
}

