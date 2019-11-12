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
    int n; cin>>n;
    string s,t; cin>>s>>t;
    vi v;
    for(int i = 0; i < n; i++){
        if(s[i]!=t[i]) v.pb(i);
    }
    if(v.size()==0){
        cout<<"NO\n";
        return;
    } 
    if(v.size()!=2){
        cout<<"NO\n";
        return;
    } 
    if(v.size()==2){
        if(s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]]){
            cout<<"YES\n";
            return;
        }
        else cout<<"NO\n";
    }

}

int main(){
    int t = 1;
    cin>>t;
    while(t--) solve();
}