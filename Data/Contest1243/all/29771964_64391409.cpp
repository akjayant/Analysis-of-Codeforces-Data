#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int k;cin>>k;
    REP(q,k){
        int n;cin>>n;
        string s,t;cin>>s>>t;
        map<char,int> mp;
        REP(i,n) {
            mp[s[i]]++;
            mp[t[i]]++;
        }
        bool ok=true;
        int l=0;
        vector<pair<int,int>> ans;
        for(auto e:mp){
            if(e.second&1){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"No"<<endl;
            continue;
        }else{
            cout<<"Yes"<<endl;
            REP(i,n){
                rep(j,i+1,n){
                    if(t[j]==s[i]){
                        swap(s[j],t[j]);
                        ans.push_back(make_pair(j,j));
                        swap(s[j],t[i]);
                        ans.push_back(make_pair(j,i));
                        break;
                    }
                    if(s[j]==s[i]){
                        swap(s[j],t[i]);
                        ans.push_back(make_pair(j,i));
                        break;
                    }
                }
            }
            cout<<ans.size()<<endl;
            REP(i,ans.size()){
                cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
            }
        }
    }
}