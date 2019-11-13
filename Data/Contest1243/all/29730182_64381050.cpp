#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N= 1e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ll test,n;
    string s,t;
    cin>>test;

    while(test-->0){
        cin>>n>>s>>t;

        vector<ll> diff;
        for(ll i=0;i<n;i++)if(s[i]!=t[i])diff.push_back(i);

        if(diff.size()>2 || diff.size()==1){
            cout<<"No\n";
            continue;
        }

        if(diff.size()==0){
            set<char>st;
            bool flg=false;
            for(ll i=0;i<n;i++){
                if(st.count(s[i]))
                    flg=true;
                st.insert(s[i]);
            }
            if(flg)cout<<"Yes\n";
            else cout<<"No\n";
            continue;
        }

        swap(s[diff[0]] , t[diff[1]]);
        if(s==t)cout<<"Yes\n";
        else cout<<"No\n";
    }
}

