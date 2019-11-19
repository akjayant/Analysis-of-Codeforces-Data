#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

const int N = 1e6+100;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 1e9, r = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            ans = max(ans , max(2 * (i + 1) , 2 * (n - i)));
            r = i;
        }
    }

    if(r == -1){
        cout << n << endl;
        return;
    }
    cout << ans << endl;

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
