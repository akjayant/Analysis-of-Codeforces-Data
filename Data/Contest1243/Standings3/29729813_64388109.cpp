#include "bits/stdc++.h"
using namespace std;

char s[50000],t[50000];

int cnt[26];
int n;

bool bad() {
    for(int i=0;i<26;i++) if(cnt[i]&1) return true;
    return false;
}



int main() {
    ios::sync_with_stdio(0);
    int T; cin>>T;
    while(T--) {
        cin>>n;
        cin>>s>>t;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) cnt[s[i]-'a']++;
        for(int i=0;i<n;i++) cnt[t[i]-'a']++;
        if(bad()) {
            cout<<"NO"<<endl;
            continue;
        }
        int d=0;
        string u,v;
        for(int i=0;i<n;i++) {
            if(s[i]!=t[i]) {
                d++;
                u.push_back(s[i]);
                v.push_back(t[i]);
            }
        }
        if(d==2 && u[0]==u[1] &&v[0]==v[1]) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
