#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN=3e3+1;
const int inf = MAXN;
vector<vector<int>> trans(MAXN, vector<int>(0));

int n;
vector<pair<int , int>> ans(0);
void solve(){
    ans.clear();
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) continue;
        int upInd=-1;
        int downInd=-1;
        for(int j=i+1;j<n;j++){
            if(s[j]==s[i]) upInd=j;
            if(t[j]==s[i]) downInd=j;
        }
        if(upInd==-1 && downInd==-1){
            cout<<"No"<<endl;
            return;
        }
        if(upInd==-1){
            ans.push_back({downInd, downInd});
            swap(s[downInd], t[downInd]);
            ans.push_back({downInd, i});
            swap(t[i], s[downInd]);
        }
        else{
            ans.push_back({upInd, i});
            swap(s[upInd], t[i]);
        }
    }
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(auto &son:ans){
        cout<<(son.first+1)<<" "<<(son.second+1)<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}