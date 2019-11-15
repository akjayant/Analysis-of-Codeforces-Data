/*input
4
5
souse
houhe
3
cat
dog
2
aa
az
3
abc
bca
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    vector<char> v,g;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != b[i]){
            v.pb(a[i]);
            g.pb(b[i]);
        }
    }
    if(v.size() == 1){
        cout << "NO\n";
        return;
    }
    if(v.size() == 2){
        if(v[0] == v[1] && g[0] == g[1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
signed main() {
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
return 0;
}
