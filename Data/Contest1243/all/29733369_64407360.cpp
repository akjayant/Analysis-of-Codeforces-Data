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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    int cnt=0;
    while (n%2LL==0) ++cnt, n>>=1LL;
    if (n==1) {
        if (cnt==0) cout<<1;
        else cout<<2;
    } else {
        if (cnt>0) cout<<1;
        else {
            vector<ll> uoc;
            for (ll i=2; i*i<=n; ++i) {
                if (n%i==0) {
                    uoc.emb(i);
                    if (i!=n/i) uoc.emb(n/i);
                }
            }

            ll res=n;
            if (!uoc.empty()) res=uoc[0];
            for (int i=1; i<(int)uoc.size(); ++i) {
                if (uoc[i]%uoc[0]!=0) {
                    res=1;
                    break;
                }
            }
            cout<<res;
        }
    }
    return 0;
}