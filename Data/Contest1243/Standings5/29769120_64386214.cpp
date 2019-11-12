#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t;
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>t;
      while(t--){
        cin>>n;
        string s1,s2;
        ll f=0,fl=0,fl2=0;
        pair<char,char>p={'.','.'};
        cin>>s1>>s2;
        for(int i=0;i<n;i++){
          if(fl2==1&&s1[i]!=s2[i]){
            fl=0;
            break;
          }
          if(s1[i]!=s2[i] &&f==0)p={s1[i],s2[i]},f=1;
          else if(s1[i]!=s2[i]&&f==1){
            if(p.first==s1[i] && p.second==s2[i]) fl=1;
            fl2=1;
          }
        }
        if(fl==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
      } 
}