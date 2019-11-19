#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int t, n;
string s;
int main(){
    cin >> t;
    while(t --){
        cin >> n >> s;
        int l = n, r = -1, z = 0;
        for(int i = 0; i < n; ++ i){
            if(s[i] == '1'){
                l = min(i, l);
                r = max(i, r);
                ++ z;
            }
        }
        int ans = n;
        if(l != n){
            ans = max(ans, 2 * n - l * 2);
        }
        if(r != -1){
            ans = max(ans, 2 * n - (n - 1 - r) * 2);
        }
        ans = max(ans, n + z);
        cout << ans << endl;
    }

    return 0;
}