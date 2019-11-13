#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,q;
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>q;
      while(q--){
        cin>>n;
        string s,t;
        ll f=0;
        cin>>s>>t;
        ll fs[26]={0};
        for(int i=0;i<n;i++){
           fs[s[i]-'a']++;
           fs[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
          if(fs[i]%2){f=1;break;}
        }
        if(f==1) cout<<"No"<<endl;
        else{
          cout<<"Yes"<<endl;
          vector<pair<ll,ll>>v;
           for(int i=0;i<n;i++){
             if(s[i]!=t[i]){
                ll x=i+1;
                while(true){
                   if(s[x]==s[i]||t[x]==s[i])
                    break;
                   x++;
                }
                if(s[x]==s[i]){
                  v.push_back({x+1,i+1});
                  swap(s[x],t[i]);
                }
                else if(t[x]==s[i]){
                  v.push_back({x+1,x+1});
                  v.push_back({x+1,i+1});
                  swap(s[x],t[x]);
                  swap(t[i],s[x]);
                }
             }
           }
           cout<<v.size()<<endl;
           for(int i=0;i<v.size();i++){
             cout<<v[i].first<<" "<<v[i].second<<endl;
           }
        }
      } 
}