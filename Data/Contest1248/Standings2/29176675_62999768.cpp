#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[1111];
string s, t;

ll solve(){
    ll cnt = 0, M = 1e9, res = 0;
    for (int i = 0; i < n + 1; i++) a[i] = 0;
    for (int i = 1; i <= n; i++){
        if (t[i] == '(') cnt++; else cnt--;
        a[i] = cnt;
        M = min(M, a[i]);
    }
    if (cnt != 0) return 0;
    if (M != 0){
        for (int i = 1; i <= n; i++){ 
            if (a[i] == M){
                res = 1, cnt = 0;
                for (int j = i + 1; j <= n; j++){
                    if (t[j] == '(') cnt++; else cnt--;
                    if (cnt == 0) res++;
                }
                return res;
            }
        }
    }
    else{
        for (int i = 1; i <= n; i++) if (a[i] == 0) res++;
        return res;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> s;
    s = " " + s;
    ll ans = 0, lef = 1, rig = 1;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            t = s;
            swap(t[i], t[j]);
            if (solve() > ans){
                ans = solve();
                lef = i, rig = j;
            }
        }
    }
    cout << ans << endl << lef << ' ' << rig;
    
    return 0;
}
