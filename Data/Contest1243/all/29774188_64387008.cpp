#include <bits/stdc++.h>
using namespace std;
#define im 2147483647
#define lm 9223372036854775807
#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define ff first
#define ss second
#define _graph map<int, vector<int>>
#define lower_str(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define upper_str(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define debug(index, num) cout << "Case #" << index << ": " << num << endl
#define nmax(an, na) an = max(an, na)
#define nmin(an, na) an = min(an, na)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define repp2(i, a, b) for (int i = a-1; i >= b; i--)
#define be(x) x.begin(), x.end()
#define rbe(x) x.rbegin(), x.rend()
#define pb push_back
#define IO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main () {
    IO;
    int n, k;
    cin >> k;
    while(k--) {
        cin >> n;
        string s, t;
        cin >> s >> t;
        int f = 0;
        string ss, tt;
        rep(i , 0, n) {
            if(t[i] == s[i]) continue;
            ss.pb(s[i]);
            tt.pb(t[i]);
            f++;
        }
        if(f != 2) cout << "No\n";
        else{
            swap(ss[0], tt[0]);
            sort(be(ss));
            sort(be(tt));
            if(tt == ss) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}