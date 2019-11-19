#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

void solve(){
    int n; string S;
    cin>>n>>S;

    int cnt=-1;
    for (int i = 0; i < n; ++i) {
        if(S[i]=='1'){
            cnt=max(cnt,max(i+1,n-i));
        }
    }
    if(cnt==-1){
        cout<<n<<endl;
        return;
    }
    cout<<cnt*2<<endl;

    return;
}


int main() {
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
    return 0;
}
