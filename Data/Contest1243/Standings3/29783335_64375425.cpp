#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

void solve(){
    int N; cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=-1;
    for (int i = 1; i <=N; ++i) {
        int cnt=a.end()-lower_bound(a.begin(),a.end(),i);
        if(cnt>=i) ans=i;
    }
    cout<<ans<<endl;
}

int main() {
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
    return 0;
}
