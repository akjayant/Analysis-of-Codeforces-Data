//#pragma comment(linker,"/STACK:36777216")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define itoc(c) (char)((int)'0' + c)
#define ctoi(c) (int)(c - '0')
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define emb emplace_back
#define pb push_back

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

const int oo = 1e9;
const int MOD = 1e9+7;
const int N = 2e5+5;

int n;
string s,t;

void solve() {
    vector<pii> res;
    for (int i=0; i<n; ++i) {
        if (s[i]==t[i]) continue;
        int x=-1;
        for (int j=i+1; j<n; ++j) {
            if (s[j]==s[i]) {
                x=j;
                break;
            }
        }
        if (x<0) {
            int y=-1;
            for (int j=i+1; j<n; ++j)
                if (t[j]==s[i]) {
                    y=j;
                    break;
                }
            if (y<0) {
                cout<<"No\n";
                return;
            }
            res.emb(i+1, y);
            swap(s[i+1], t[y]);
            x=i+1;
        }
        res.emb(x,i);
        swap(s[x], t[i]);
    }
    cout<<"Yes\n";
    cout<<res.size()<<"\n";
    for (pii r: res) cout<<r.first+1<<" "<<r.second+1<<"\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k; cin>>k;
    while (k--) {
        cin>>n>>s>>t;
        solve();
    }
    return 0;
}