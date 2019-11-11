#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    int n;
    cin >> n;
    int r1, p1, s1;
    cin >> r1 >> p1 >> s1;
    string s;
    cin >> s;
    int r2 = 0, p2 = 0, s2 = 0;
    for(auto c : s){
        if(c == 'R') r2++;
        if(c == 'P') p2++;
        if(c == 'S') s2++;
    }
    if(min(r1, s2) + min(p1, r2) + min(s1, p2) < (n+1)/2){
        cout << "NO\n";
        return;
    }
    string res = "";
    for(auto c : s){
        if(c == 'R'){
            if(p1) res += "P", p1--;
            else res += "N";
        }
        else if(c == 'P'){
            if(s1) res += "S", s1--;
            else res += "N";
        }
        else if(c == 'S'){
            if(r1) res += "R", r1--;
            else res += "N";
        }
    }
    for(int i=0; i<n; i++){
        if(res[i] == 'N'){
            if(p1) res[i] = 'P', p1--;
            else if(s1) res[i] = 'S', s1--;
            else res[i] = 'R';
        }
    }
    cout << "YES\n";
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
