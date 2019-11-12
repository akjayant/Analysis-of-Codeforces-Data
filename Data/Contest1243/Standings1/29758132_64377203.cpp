#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=764983111ll;
const long long mod2=764983113ll;
bool ok[200001];
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    for (int i=0;i<n;i++) ok[i]=(s[i]!=t[i]);
    int cnt=0;
    for (int i=0;i<n;++i){
        cnt+=ok[i];
    }
    if (cnt!=2){
        cout<<"No\n";
        return;
    }
    int x,y;
    x=y=-1;
    for (int i=0;i<n;i++){
        if (ok[i]){
            if (x==-1) x=i;
            else y=i;
        }
    }
    if (s[x]==s[y] && t[x]==t[y]) cout<<"Yes\n";
    else cout<<"No\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

