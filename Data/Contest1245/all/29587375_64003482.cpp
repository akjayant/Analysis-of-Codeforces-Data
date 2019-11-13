//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

void solve(){
    string s, ss;
    ll n, x, y, z;
    cin >> n >> x >> y >> z >> s;
    ss = s;
    for(int i = 0; i < s.size(); ++i){
        ss[i] = '!';
    }
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'R' and y)   ss[i] = 'P', --y, ++res;
        if(s[i] == 'P' and z)   ss[i] = 'S', --z, ++res;
        if(s[i] == 'S' and x)   ss[i] = 'R', --x, ++res;
    }
    if(res >= ((n + 1) / 2)){
        cout << "YES\n";
        for(int i = 0; i < ss.size(); ++i){
            if(ss[i] == '!'){
                if(x)   ss[i] = 'R', --x;
                else if(y)  ss[i] = 'P', --y;
                else if(z)  ss[i] = 'S', --z;   
            }
        }
        cout << ss << "\n";
    }
    else    cout << "NO\n";
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        res = 0;
        solve();
    }
}
// nEro