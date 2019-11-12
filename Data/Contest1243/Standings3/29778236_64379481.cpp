#include<bits/stdc++.h>
//#define int long long

typedef long long ll;
typedef long double ld;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> k(n, 0);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    int ma = 0;
    for(int i = 0; i < n; i++){
        ma = max(ma, min(i + 1, k[i]));
    }
    cout << ma << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test =  1;
    cin >> test;
    while(test--){
        solve();
    }
}
