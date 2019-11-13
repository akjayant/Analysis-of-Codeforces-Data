#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define ll long long 
#define N 100005
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define piii pair<int, pii>
#define print(x) cout << #x << "=" << x << "\t";
#define endl "\n"
#define newline cout << endl;

int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for(int i = 0; i <= a; i++) {
            int ff = min(i, b / 2);
            int ss = min(b - 2 * ff, c / 2);
            ans = max(ans, 3 * ff + 3 * ss);
        }
        cout << ans << endl;
    }
    return 0;
}
