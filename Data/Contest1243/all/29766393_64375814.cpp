#include<bits/stdc++.h>
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    auto A = vector<int>(n);
    for(auto& a : A)
        cin >> a;
    
    sort(A.begin(), A.end(), greater<int>());

    auto ans = 0;
    for(auto i = 0; i < A.size(); ++i) {
        auto candi = min(i+1, A[i]);
        ans = max(ans, candi);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    for(auto i = 0; i < t; ++i)
        solve();
}