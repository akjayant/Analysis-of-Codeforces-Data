#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define endl '\n'

using namespace std;

signed main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int i, j, l, n;
    cin >> n;
    string s; cin >> s;
    int ans = 0, ans_l = 1, ans_r = 1;
    for (i = 0; i < n; i++){
        for (j = i; j < n; j++){
            swap(s[i], s[j]);
            vector < int > bal(n, 0);
            if (s[0] == '('){
                bal[0]++;
            }
            else{
                bal[0]--;
            }
            for (l = 1; l < n; l++){
                if (s[l] == '('){
                    bal[l]++;
                }
                else{
                    bal[l]--;
                }
                bal[l] += bal[l - 1];
            }
            int mi_bal = 1e7;
            for (l = 0; l < n; l++){
                mi_bal = min(mi_bal, bal[l]);
            }
            int cur = 0;
            for (l = 0; l < n; l++){
                if (bal[n - 1] == 0 and bal[l] == mi_bal){
                    cur++;
                }
            }
            if (cur > ans){
                ans = cur; ans_l = i + 1; ans_r = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << endl << ans_l << " " << ans_r << endl;

    return 0;

}
