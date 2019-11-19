#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

void solve(){
    ll N; cin>>N;
    ll tmp=N;
    for(ll i=2ll;i<=sqrt(N);++i){
        if(tmp%i==0){
            while(tmp%i==0){
                tmp/=i;
            }
            if(tmp>1){
                cout<<1<<endl;
                return;
            }else{
                cout<<i<<endl;
                return;
            }
        }
    }
    cout<<N<<endl;
}

int main() {
    solve();
    return 0;
}
