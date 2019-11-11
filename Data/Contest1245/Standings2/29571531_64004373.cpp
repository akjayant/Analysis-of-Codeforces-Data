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

const ll MOD = 1e9+7;
const int N = 1e5+5;

string s;
int n;
ll f[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.length();
    f[0]=f[1]=1LL;
    for (int i=0; i<n; ++i) {
        if (s[i]=='w' || s[i]=='m') {
            cout<<0;
            return 0;
        }
    }
    for (int i=2; i<=n; ++i) {
        if (s[i-2]=='u' && s[i-1]=='u') f[i]=(f[i-1]+f[i-2])%MOD;
        else if (s[i-2]=='n' && s[i-1]=='n') f[i]=(f[i-1]+f[i-2])%MOD;
        else f[i]=f[i-1];
    }
    cout<<f[n];
    return 0;
}