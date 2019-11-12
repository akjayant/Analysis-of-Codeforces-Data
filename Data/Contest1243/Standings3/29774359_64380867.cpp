#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll test;
    for(cin>>test;test>0;test--) {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<int> pos;
        int num[26]={0};
        bool found = false;
        for(int i = 0;i<n;i++) {
            if(s1[i]!=s2[i])
                pos.push_back(i);
            if(num[s1[i]-'a']==1)
                found = true;
            num[s1[i]-'a']++;
        }
        if(pos.size()==2) {
            int a1 = pos[0];
            int a2 = pos[1];
            if(s1[a1]==s1[a2]&&s2[a1]==s2[a2])
                cout<<"Yes";
            else
                cout<<"No";
        }
        else if(pos.size()==0){
            if(found)
                cout<<"Yes";
            else
                cout<<"No";
        }
        else {
            cout<<"No";
        }
        cout<<endl;
    }
}