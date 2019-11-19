#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 1; i <= n; i++){
            int p;
            cin >> p;
            if(p % 2 == 0) cnt1++;
            else cnt2++;
        }
        int m;
        cin >> m;
        int cnt3 = 0;
        int cnt4 = 0;
        for(int i = 1; i <= m; i++){
            int q;
            cin >> q;
            if(q % 2 == 0) cnt3++;
            else cnt4++;

        }
        ll ans = (ll)cnt1 * cnt3 + (ll)cnt2 * cnt4;
        cout << ans << '\n';
    }

    return 0;
}
