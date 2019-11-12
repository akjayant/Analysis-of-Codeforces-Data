#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int t;
    cin >> t;
    int a,b,c;
    REP(i,t){
        cin >> a >> b >> c;
        int ans = 0;
        ans += 3 * min(b, c / 2);
        b -= min(b, c / 2);
        ans += 3 * min(a, b / 2);
        cout << ans << endl;
    }
    return 0;
}