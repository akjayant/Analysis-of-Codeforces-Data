#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int cnt1 = min(a, b/2);
        int cnt2 = min(b-cnt1*2, c/2);
        int ans = (cnt1+cnt2)*3;

        cnt1 = min(b, c/2);
        cnt2 = min(a, (b-cnt1)/2);
        ans = max(ans, (cnt1+cnt2)*3);
        cout << ans << endl;
    }
}
