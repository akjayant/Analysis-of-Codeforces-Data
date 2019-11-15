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
    vector<int> cnt(26,0);
    for (int i = 0; i < N; ++i) {
        ++cnt[s[i]-'a'];
        ++cnt[t[i]-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if(cnt[i]%2==1){
            cout<<"No"<<endl;
            return;
        }
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < N; ++i) {
        if(s[i]==t[i]) continue;

        for (int j = i+1; j < N; ++j) {
            if(s[j]==s[i]){
                swap(s[j],t[i]);
                ans.push_back(make_pair(j,i));
                break;
            }
        }
        if(s[i]==t[i]) continue;
        for (int j = i+1; j < N; ++j) {
            if(t[j]==s[i]){
                swap(t[j],s[j]);
                swap(s[j],t[i]);
                ans.push_back(make_pair(j,j));
                ans.push_back(make_pair(j,i));
                break;
            }
        }
    }
    /*
    if(s!=t){
        cout<<"No"<<endl;
        return;
    }
     */
    cout<<"Yes"<<endl;
    //cout<<s<<endl<<t<<endl;
    cout<<ans.size()<<endl;
    for(auto a:ans){
        cout<<a.first+1<<" "<<a.second+1<<endl;
    }

}

int main() {
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
    return 0;
}