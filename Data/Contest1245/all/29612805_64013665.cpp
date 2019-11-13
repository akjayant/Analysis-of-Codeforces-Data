#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n; cin >> n;
    int jr, jp, js; cin >> jr >> jp >> js;

    string bob; cin >> bob;
    string ans; ans.resize(bob.length(), '-');

    for(int i = 0; i < (int) bob.length(); i++){
        char c = bob[i];

        if(c == 'P' && js > 0){
            js--;
            ans[i] = 'S';
        }
        if(c == 'R' && jp > 0){
            jp--;
            ans[i] = 'P';
        }
        if(c == 'S' && jr > 0){
            jr--;
            ans[i] = 'R';
        }
    }

    int gagne = 0;
    for(int i = 0; i < (int) ans.length(); i++)
    {
        if(ans[i] == '-'){
            if(jr>0) ans[i] = 'R', jr--;
            else if(jp > 0) ans[i] = 'P', jp--;
            else ans[i] = 'S', js--;
        }

        char x = ans[i], y =bob[i];
        if((x == 'R' && y == 'S') || (x == 'P' && y == 'R') || (x == 'S' && y == 'P'))
            gagne++;
    }
    
    if(gagne * 2 >= n && js == 0) cout << "YES\n" << ans << "\n";
    else cout << "NO\n" ;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
        solve();
}