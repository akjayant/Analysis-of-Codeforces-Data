#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second
#define pb push_back
#define FASTER { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;



int main(){
    FASTER
//    freopen("x.INP", "r", stdin);
//    freopen("x.OUT", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int a, b, c, n, Count = 0;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        string ans(n, '.');
        int cntR = 0, cntP = 0, cntS = 0;
        REP(i, n){
            if (s[i] == 'R') cntR++;
            else if (s[i] == 'P') cntP++;
            else cntS++;
        }
        int w = min(cntR, b) + min(c, cntP) + min(a, cntS);
        REP(i, n) if (b > 0 && s[i] == 'R') ans[i] = 'P', b--;
        REP(i, n) if (c > 0 && s[i] == 'P') ans[i] = 'S', c--;
        REP(i, n) if (a > 0 && s[i] == 'S') ans[i] = 'R', a--;
        REP(i, n){
            if (ans[i] == '.' && a > 0) ans[i] = 'R', a--;
            else if (ans[i] == '.' && b > 0) ans[i] = 'P', b--;
            else if (ans[i] == '.' && c > 0) ans[i] = 'S', c--;
        }
        if (w >= (n+1)/2) cout << "YES\n" << ans << '\n';
        else cout << "NO\n";
    }
}
