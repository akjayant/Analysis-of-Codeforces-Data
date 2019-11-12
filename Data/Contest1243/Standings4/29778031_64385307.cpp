#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int N = int(5e5) + 12, mod = int(1e9)  + 7;
int a[N];
string s, t;
map<char, int> m1, m2;
vector<pair<int, int> > ans;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--) {
        int n;
        cin>>n;
        cin>>s>>t;
        if(s == t) {
            cout<<"Yes"<<endl<<0<<endl;
            continue;
        }
        ans.clear();
        for(char i='a';i<='z';i++) {
            m1[i] = 0;
            m2[i] = 0;
        }
        for(int i=0;i<n;i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        bool p = 1;
        for(char i = 'a'; i <= 'z'; i++) {
            if((m1[i] + m2[i]) % 2) {
                p = 0;
                break;
            }
            m1[i] = 0;
            m2[i] = 0;
        }
        if(p == 0) {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++) {
            if(s[i] == t[i])
                continue;
            bool p = 0;
            for(int j = i + 1;j<n;j++) {
                if(t[i] == t[j]) {
                    swap(s[i], t[j]);
                    ans.push_back({i, j});
                    p = 1;
                    break;
                }
            }
            if(p)
                continue;
            for(int j=i+1;j<n;j++) {
                if(t[i] == s[j]) {
                    swap(s[j], t[j]);
                    swap(s[i], t[j]);
                    ans.push_back({j, j});
                    ans.push_back({i, j});
                    break;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i].ff + 1<<" "<<ans[i].ss + 1<<endl;
        }
    }
}
/*
 5 5 6
 1 2 3 4 5
 1 2 1 1
 2 3 1 3
 4 2 4 4
 2 5 1 4
 3 2 2 3
 3 2 3 3
 */
