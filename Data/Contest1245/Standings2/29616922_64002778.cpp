#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i = (a); i<= (b); ++i)
#define L first
#define R second

using namespace std;

const int M=1e5+5;
const ll INF = 1e18;

int n,r,p,s;
string st;
char ans[M];
bool solve() {
    cin>>n;
    cin>>r>>p>>s;
    cin>>st;
    for(int i=0; i<n; i++) {
        switch(st[i]) {
            case 'R': if(p>0) ans[i] = 'P', p--; else ans[i] = '0';  break;
            case 'P': if(s>0) ans[i] = 'S', s--; else ans[i] = '0';  break;
            case 'S': if(r>0) ans[i] = 'R', r--; else ans[i] = '0';  break;
        }
    }
    if(p+s+r <= n/2) {
        cout<<"YES\n";
        for(int i=0; i<n; i++) {
            if(ans[i] != '0') cout<<ans[i];
            else {
                if(p > 0) cout<<"P", p--;
                else if(r > 0) cout<<"R", r--;
                else cout<<"S", s--;
            }
        }
        cout<<"\n";
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
  //  freopen("input.txt","r",stdin);
    int t; ll a,b;
    cin>>t;
    while(t--) {
        if(!solve()) cout<<"NO\n";
    }
    return 0;
}
