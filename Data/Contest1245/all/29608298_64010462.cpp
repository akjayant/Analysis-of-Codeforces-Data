#include<bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld double
#define null nullptr
#define endl '\n'

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 7;
const int M = 1e9 + 7;

int t, n, a, b, c;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while (t--){
        cin >> n >> a >> b >> c;
        cin >> s;
        int A = 0, B = 0, C = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R') A++;
            if (s[i] == 'P') B++;
            if (s[i] == 'S') C++;
        }
        int sc = min(a, C) + min(b, A) + min(c, B);
        int ca = a - min(a, C);
        int cb = b - min(b, A);
        int cc = c - min(c, B);
        if (sc*2 >= n){
            cout << "YES" << endl;
            string res = s;
            for (int i = 0; i < s.size(); i++){
                if (s[i] == 'R' && b > 0){
                    b--;
                    res[i] = 'P';
                }
                else if (s[i] == 'R'){
                    if (ca) res[i] = 'R', ca--;
                    else if (cc) res[i] = 'S', cc--;
                }
                if (s[i] == 'P' && c > 0){
                    c--;
                    res[i] = 'S';
                }
                else if (s[i] == 'P'){
                    if (ca) res[i] = 'R', ca--;
                    else if (cb) res[i] = 'P', cb--;
                }
                if (s[i] == 'S' && a > 0){
                    a--;
                    res[i] = 'R';
                }
                else if (s[i] == 'S'){
                    if (cc) res[i] = 'S', cc--;
                    else if (cb) res[i] = 'P', cb--;
                }
            }
            cout << res << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
