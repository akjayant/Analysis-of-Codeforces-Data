#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, a, b, c;

int main(){



    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        int ans = 0;
        while (true){
            if (b > 0 && c > 1){ans += 3, --b, c -= 2; continue;}
            if (a > 0 && b > 1){ans += 3; --a, b -= 2; continue;}
            break;
        }
        cout << ans << '\n';
    }



}
