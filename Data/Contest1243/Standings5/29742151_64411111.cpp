//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itmin(x,y) (x) = min((x),(y));
#define itmax(x,y) (x) = max((x),(y));
#define cotu cout
#define itn int
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 7;

void solve(){
    int n, sum = 0; cin>>n;
    string s,t; cin>>s>>t;
    map<int,int> f;
    for(int i = 0; i < n; i++){
        f[s[i]-'a']++;
        f[t[i]-'a']++;
        if(s[i]!=t[i]) sum++;
    }
    for(auto it: f){
        if(it.S%2==1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

    vector<ii> ans;
    for(int i = 0; i < n; i++){
        if(s[i]==t[i]) continue;
        if(sum==2){
            for(int j = i+1; j < n; j++){
                if(s[j]!=t[j]){
                    if(s[i]==s[j] && t[i]==t[j]) ans.pb({i,j});
                    else{
                        ans.pb({i,i});
                        ans.pb({i,j});
                    }
                    break;
                }
            }
            break;
        }
        else{
            for(int j = i+1; j < n; j++){
                if(s[j]==t[j]) continue;
                if(t[i]==t[j]){
                    ans.pb({i,j});
                    swap(s[i],t[j]);
                    sum--;
                    if(s[j]==t[j]) sum--;
                    break;
                }
                else if(t[i]==s[j]){
                    ans.pb({j,j});
                    swap(s[j],t[j]);
                    ans.pb({i,j});
                    swap(s[i],t[j]);
                    sum--;
                    if(s[j]==t[j]) sum--;
                    break;
                }
            }
        }
    }

    assert(ans.size()<=2*n);
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.F+1<<" "<<it.S+1<<endl;
    }
}

int main(){
    int t = 1;
    cin>>t;
    while(t--) solve();
}