#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        vector <char> ans(n, '\0');
        cin >> s;
        int q = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'R' && b > 0){
                b--;
                ans[i] = 'P';
                q++;
            }
            if (s[i] == 'P' && c > 0){
                c--;
                ans[i] = 'S';
                q++;
            }
            if (s[i] == 'S' && a > 0){
                a--;
                ans[i] = 'R';
                q++;
            }
        }
        if (q < (n + 1) / 2){
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
        for (int i = 0; i < n; i++)
            if (ans[i] != '\0')
                cout << ans[i];
            else
            if (a > 0){
                cout << 'R';
                a--;
            }
            else if (b > 0){
                cout << 'P';
                b--;
            }
            else {
                cout << "S";
                c--;
            }
        cout << '\n';
    }
    return 0;
}
