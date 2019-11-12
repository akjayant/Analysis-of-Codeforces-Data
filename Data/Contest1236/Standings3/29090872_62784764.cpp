#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int temp = min(b, c / 2);
        ans += temp * 3;
        b -= temp;
        c -= temp * 2;
        ans += min(b / 2, a) * 3;
        cout << ans << endl;

    }


    return 0;
}