#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 1e9;
        for(int i = 0 ; i <= 100 ; i ++){
            for(int j = 0 ; j <= 100 ; j++){
                int new_a = a - i, new_b = b - 2 * i, new_c = c;
                new_b -= j, new_c -= 2 * j;
                if (new_a >= 0 && new_b >= 0 && new_c >= 0){
                    ans = min(ans, new_b + new_c + new_a);
                }
            }
        }
        cout << a + b + c - ans << "\n";
    }

    return 0;
}