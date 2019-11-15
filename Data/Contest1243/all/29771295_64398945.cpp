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
   string s,t;
   cin >> s >> t;
   vector<pair<char,int>> v,g;
   for(int i = 0 ; i < n ; i++){
        if(s[i] == t[i])continue;
        v.pb({s[i],i+1});
        g.pb({t[i],i+1});
   }
   vector<pii> ans;
   for(int i = 0 ; i < v.size() ; i++){
        if(v[i].f == g[i].f)continue;
        bool f = 0;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j].f == v[i].f){
                swap(g[i].f,v[j].f);
                f = 1;
                ans.pb({v[j].s,g[i].s});
                break;
            }
        }
        if(!f){
            for(int j = i + 1; j < v.size(); j++){
                if(g[j].f == v[i].f){
                    swap(g[j].f,v[j].f);
                    swap(g[i].f,v[j].f);
                    f = 1;
                    ans.pb({g[j].s,v[j].s});
                    ans.pb({v[j].s,g[i].s});
                    break;       
                }
            }
        }
        if(!f){
            cout << "NO\n";
            return;
        }
            
   }
   cout << "YES\n";
   cout << ans.size() << endl;
   for(auto x : ans){
    cout << x.f << " " << x.s << endl;
   }
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
