#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> q;

    while(q--){
        int n; cin >> n;
        int ans = n;
        for(int i = 0; i < n; ++i){
            char a; cin >> a;
            if(a == '1'){
                ans = max(ans, max(i + i + 2, n - i + n - i));
            }
        }
        cout << ans << endl;
    }
}
