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
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> h;
        for (int i=1; i<=n; ++i) {
            int x; cin>>x;
            h.emplace_back(x);
        }
        sort(all(h), greater<int>());
        int r=0;
        while (r<n && h[r]>r) ++r;
        cout<<r<<"\n";
    }
    return 0;
}