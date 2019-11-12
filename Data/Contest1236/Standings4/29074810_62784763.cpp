#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second


using namespace std;
typedef pair <int, int> ii;




int main(){
    int T;
    cin >> T;
    while (T--){
        int a, b, c;
        int ans = 0;
        cin >> a >> b >> c;
        FOR(i, 0, 100) FOR(j, 0, 100){
            if (i <= a && 2*i + j <= b && 2*j <= c) ans = max(ans, i + 2*i + j + 2*j);
        }
        cout << ans << '\n';
    }
}
