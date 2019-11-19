#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 123456;
 
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll res;
        string s;
        cin >> res >> s;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1')
            res = max({res, (ll)(i + 1) * 2, (ll)(s.size() - i) * 2});
        }
        cout << res << "\n";
    }
}