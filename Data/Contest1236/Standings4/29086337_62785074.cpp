#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

const int INF = 0x3c3c3c3c;
const ll INF_L = 0x3c3c3c3c3c3c3c3c;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(a - i >= 0 && b - 2 * i - j >= 0 && c - 2 * j >= 0){
                ans = max(ans, 3 * i + 3 * j); 
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        solve();
    }
}