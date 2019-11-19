#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    for(int y = 0; y < w; y++){
        if((p - y * d) % w == 0){
            int x = (p - y * d) / w;
            if(x < 0){
                cout << "-1";
                return 0;
            }
            if(x + y > n){
                cout << "-1";
                return 0;
            }
            cout << x << " " << y << " " << n - x - y;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
