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
        int n,a,b,c; cin>>n>>a>>b>>c;
        int cnt=0;
        char res[n+1]={0};
        for (int i=1; i<=n; ++i) {
            char x; cin>>x;
            if (x=='R' && b>0) ++cnt, --b, res[i]='P';
            if (x=='P' && c>0) ++cnt, --c, res[i]='S';
            if (x=='S' && a>0) ++cnt, --a, res[i]='R';
        }
        if (2*cnt>=n) {
            cout<<"YES\n";
            for (int i=1; i<=n; ++i) {
                if (res[i]!=0) cout<<res[i];
                else {
                    if (a>0) cout<<'R', --a;
                    else if (b>0) cout<<'P', --b;
                    else cout<<'S', --c;
                }
            }
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}