#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;
const int MOD = 1000000007;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    s.clear();
    cin >> s;
    int d[500];
    memset(d, 0, sizeof(d));
    for(int i = 0; i < n; i++)
        d[s[i]]++;
    int x, y, z;
    x = min(a, d['S']);
    y = min(b, d['R']);
    z = min(c, d['P']);
    char st[500];
    for(int i = 0; i < n; i++)
        st[i] = '*';
    int d2[500];
    memset(d2, 0, sizeof(d2));
    d2['R'] = a;
    d2['P'] = b;
    d2['S'] = c;
    //cout << x << " " << y << " " << z << '\n';
    if (x + y + z >= (n + 1) / 2) {
        cout << "YES" << '\n';
//        for(int i = 0; i < n; i++){
//            char h = 'R';
//            if (d2[h] < d2['S']) h = 'S';
//            if (d2[h] < d2['P']) h = 'P';
//
//            if (s[i] == 'R' && d2['P'] > 0) {
//                st += 'P';
//                d2['P']--;
//            }
//            else
//            if (s[i] == 'P' && d2['S'] > 0){
//                st += 'S';
//                d2['S']--;
//            }
//            else
//            if (s[i] == 'S' && d2['R'] > 0){
//                st += 'R';
//                d2['R']--;
//            }
//            else {
//                st += h;
//                d2[h]--;
//            }
//        }
        for(int i = 0; i < n; i++){
             if (s[i] == 'R' && d2['P'] > 0) {
                st[i] = 'P';
                d2['P']--;
            }
            else
            if (s[i] == 'P' && d2['S'] > 0){
                st[i] = 'S';
                d2['S']--;
            }
            else
            if (s[i] == 'S' && d2['R'] > 0){
                st[i] = 'R';
                d2['R']--;
            }
        }

        for(int i = 0; i < n; i++){
            if (st[i] == '*'){
                if (d2['R'] > 0){
                    st[i] = 'R';
                    d2['R']--;
                    continue;
                }
                if (d2['P'] > 0){
                    st[i] = 'P';
                    d2['P']--;
                    continue;
                }
                if (d2['S'] > 0){
                    st[i] = 'S';
                    d2['S']--;
                    continue;
                }
            }
        }
        //cout << st << '\n';

        for(int i = 0; i < n; i++)
            cout << st[i];
        cout << '\n';
    }
    else cout << "NO" << '\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
  //  doc();
    int T;
    cin >> T;
    while (T--)

    solve();
}

