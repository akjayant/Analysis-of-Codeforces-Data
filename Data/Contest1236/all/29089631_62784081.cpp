#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 5, INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas --) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for(int i = 0;i <= 100;i ++) {
            for(int j = 0;j <= 100;j ++) {
                int na = i, nb = 2 * i + j, nc = 2 * j;
                if(na <= a && nb <= b && nc <= c) {
                    ans = max(ans, 3 * (i + j));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}