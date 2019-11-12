#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0);\
           cin.tie(0);\
           cout.tie(0);
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;
int n,vis[maxn];
char s[maxn],t[maxn];
vector<pii> ans;
void solve() {
    for (int i=0;i<=26;i++) if (vis[i]&1) {
        cout<<"No"<<endl;
        return;
    }
    ans.clear();
    for (int i=0;i<n;i++) if (s[i]!=t[i]) {
        for (int j=i+1;j<n;j++) if (s[j]!=t[j]) {
            if (s[j]==s[i]) {
                swap(s[j],t[i]);
                ans.push_back(make_pair(j,i));
                break;
            }
            if (t[j]==s[i]) {
                swap(s[j],t[j]);
                swap(s[j],t[i]);
                ans.push_back(make_pair(j,j));
                ans.push_back(make_pair(j,i));
                break;
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for (auto x:ans) 
        cout<<x.first+1<<" "<<x.second+1<<endl;
} 
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    IO;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>s>>t;
        for (int i=0;i<=26;i++) vis[i]=0; 
        for (int i=0;i<n;i++) vis[ s[i]-'a' ]++,vis[ t[i]-'a' ]++;
        solve();
    }
    return 0;
}