#include "bits/stdc++.h"
using namespace std;

char s[500],t[500];

int cnt[26];
int n;

bool bad() {
    for(int i=0;i<26;i++) if(cnt[i]&1) return true;
    return false;
}

int x[2222],y[2222],m;

int cal(int i,char c,char s[]) {
    for(int j=i+1;j<n;j++) {
        if(s[j]==c) return j;
    }
    return -1;
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
        cout<<"YES"<<endl;
        m=0;
        for(int i=0;i<n;i++) {
            if(s[i]==t[i]) continue;
            int f = cal(i,s[i],s);
            if(f>=0) {
                x[m]=f,y[m]=i,m++;
                swap(s[f],t[i]);
            }else {
                f=cal(i,s[i],t);
                x[m]=f,y[m]=f,m++;
                swap(s[f],t[f]);
                x[m]=f,y[m]=i,m++;
                swap(s[f],t[i]);
            }
        }
        cout<<m<<endl;
        for(int i=0;i<m;i++) cout<<x[i]+1<<" "<<y[i]+1<<endl;
        // cout<<s<<" "<<t<<endl;
    }
    return 0;
}
