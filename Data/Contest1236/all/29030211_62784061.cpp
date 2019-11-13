#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define int long long

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int n;
int a,b,c;

main () {
    cin >> n;

    while (n --) {
        cin >> a >> b >> c;

        int ans = 0;
        ans += (min(c / 2,b));
        b -= ans;
        ans *= 3;
        ans += (min(a,b / 2)) *3;

        cout << ans << endl;
    }
}
