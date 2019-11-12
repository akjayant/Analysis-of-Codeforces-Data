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
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<lli> a(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        lli ans=0, cnt=1, mn=inf;
        for (int i=n-1; i>=0; i--) {
            mn=min(mn, a[i]);
            ans=max(ans, min(mn, cnt));
            cnt++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
