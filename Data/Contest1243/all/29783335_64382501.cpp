#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

void solve(){

    int N; cin>>N;
    string s,t; cin>>s>>t;
    int cnt=0;
    int diff[2]={0};
    for (int i = 0; i < N; ++i) {
        if(s[i]!=t[i]){
            if(cnt==2){
                cout<<"No"<<endl;
                return;
            }
            diff[cnt]=i;
            ++cnt;
        }
    }
    if(cnt==0) {
        cout<<"Yes"<<endl;
        return;
    }
    if(cnt==2){
        if(s[diff[0]]==s[diff[1]]&&t[diff[0]]==t[diff[1]]){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;

}

int main() {
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
    return 0;
}
