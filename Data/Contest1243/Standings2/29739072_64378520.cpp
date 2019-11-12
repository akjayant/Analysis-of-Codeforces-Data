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
        set<char> a,b;
        map<char, int> mp;
        int count=0;
        for (int i=0; i<n; i++) {
            if (s[i]!=r[i]) {
                a.insert(s[i]);
                b.insert(r[i]);
                count++;
            }
            else {
                mp[s[i]]++;
            }
        }
        string ans="No";
        if (count==2 && a.size()==1 && b.size()==1) {
            ans="Yes";
        }
        for (auto it:mp) {
            if (count==0 && it.second>1) {
                ans="Yes";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
