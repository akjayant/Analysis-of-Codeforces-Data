#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

const int N = 1e6+100;

void solve(){
    int a , b , c , d , k;
    cin >> a >> b >> c >> d >> k;

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(i + j > k){
                continue;
            }

            int x = i * c;
            int y = j * d;

            if(x >= a && y >= b){
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }

}
