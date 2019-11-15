#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int main(){
    int t, a, b, c;
    cin >> t;
    while(t --){
        int ans = 0;
        cin >> a >> b >> c;
        ans = min(b, c / 2);
        b -= ans;
        ans += min(a, b / 2);
        cout << ans * 3<< endl;
    }

    return 0;
}