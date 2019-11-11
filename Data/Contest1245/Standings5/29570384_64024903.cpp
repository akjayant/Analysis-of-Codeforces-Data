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
    while (T--){
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}
