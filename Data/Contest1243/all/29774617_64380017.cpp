#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;
string s,t;
int n;

int main() {
    ios::sync_with_stdio(0);
    int k;cin>>k;
    while (k--) {
        cin>>n>>s>>t;
        int tepos=0; vector<int> p;
        for (int i=0; i<n; ++i)
            if (s[i]!=t[i]) {
                tepos++; p.push_back(i);
            }
        bool ans=0;
        if (tepos==2) {
            int i=p[0], j=p[1];
            ans = (s[i]==s[j] && t[i]==t[j]);
        }
        else if (tepos==0) {
            ans = true;
        }
        if (ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}