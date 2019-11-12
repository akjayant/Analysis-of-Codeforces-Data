#include <iostream>
using namespace std;

int t, a, b, c, ans;

int main(){
    cin >> t;

    while(t--){
        cin >> a >> b >> c;
        ans = 0;

        for(int i = 0; i <= a && 2 * i <= b; i++){
            for(int j = 0; j <= b - 2 * i && 2 * j <= c; j++){
                ans = max(ans, 3 * (i + j));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
