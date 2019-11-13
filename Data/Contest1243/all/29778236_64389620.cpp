#include<bits/stdc++.h>
//#define int long long

typedef long long ll;
typedef long double ld;

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    char s1, s2, t1, t2;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            if(cnt == 0){
                s1 = s[i];
                t1 = t[i];
                cnt++;
            }
            else if (cnt == 1){
                s2 = s[i];
                t2 = t[i];
                cnt++;
            }
            else if(cnt == 2){
                cout << "NO\n";
                return;
            }
        }
    }
    if(cnt != 0 && (s1 != s2 || t1 != t2 || cnt == 1)){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test =  1;
    cin >> test;
    while(test--){
        solve();
    }
}
