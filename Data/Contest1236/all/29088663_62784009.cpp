#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;cin >> t;
    while(t --){
        int a, b, c;cin >> a >> b >> c;
        int ans=0;
        for(int i=0 ; i<=a ; i++){
            int cnt = min(i, b/2);
            int cur = 3*cnt;
            cur += 3*min(b-2*cnt, c/2);
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}

