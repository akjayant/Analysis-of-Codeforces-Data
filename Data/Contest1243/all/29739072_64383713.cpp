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
        string s,r;
        cin>>s>>r;
        vector<pii> v;
        string ans="Yes";
        for (int i=0; i<n && ans=="Yes"; i++) {
            if (s[i]!=r[i]) {
                bool p=false;
                for (int j=i+1; j<n; j++) {
                    if (r[i]==r[j]) {
                        swap(s[i], r[j]);
                        v.pb(mk(i, j));
                        p=true;
                        break;
                    }
                }
                if (p==true) {
                    continue;
                }
                for (int j=i+1; j<n; j++) {
                    if (r[i]==s[j]) {
                        v.pb(mk(j, n-1));
                        swap(s[j], r[n-1]);
                        v.pb(mk(i, n-1));
                        swap(s[i], r[n-1]);
                        p=true;
                        break;
                    }
                }
                if (p==false) {
                    ans="No";
                }
            }
        }
        cout<<ans<<endl;
        if (ans=="Yes") {
            cout<<v.size()<<endl;
            for (auto it:v) {
                cout<<it.first+1<<" "<<it.second+1<<endl;
            }
        }
    }
    return 0;
}
