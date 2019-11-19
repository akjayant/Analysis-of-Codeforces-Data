#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define fi first
#define se second

const int md = (int) 1e9 + 7;
const int siz = 300005;

ll b[siz], w[siz], bb[siz], ww[siz];
ll n, m, k, l;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>n>>m;
    ll res=0;
    b[1]=1, w[1]=1;
    for(int i=2;i<=max(m, n);i++){
        w[i]+=b[i-1];
        b[i]+=w[i-1];

        ww[i]+=w[i-1];
        bb[i]+=b[i-1];

        w[i]+=bb[i-1];
        b[i]+=ww[i-1];

        b[i]%=md;
        w[i]%=md;
        bb[i]%=md;
        ww[i]%=md;
    }
    cout<<(bb[n]+ww[n]+bb[m]+ww[m]+b[n]+w[n]+b[m]+w[m]-2)%md;
    
}