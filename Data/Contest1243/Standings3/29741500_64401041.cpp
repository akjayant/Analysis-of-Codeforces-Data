#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
main()
{
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int f=0;
    // char s1,s2,t1,t2;
    int h[30]={0};
    for(int i=0;i<n;i++){
      h[s[i]-'a']++;
      h[t[i]-'a']++;
    }
    for(int i=0;i<26;i++){
      if(h[i]%2==1){
        f=1;
      }
    }
    if(f==1)cout<<"NO"<<endl;
    else {
      cout<<"YES"<<endl;
      vector<pair<int,int> > v;
      for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
          for(int j=i+1;j<n;j++){
            if(s[j]==s[i]){
              swap(t[i],s[j]);v.pb(mp(j+1,i+1));
              goto som;
            }
          }
          for(int j=i+1;j<n;j++){
            if(t[j]==t[i]){
              swap(s[i],t[j]);v.pb(mp(i+1,j+1));
              goto som;
            }
          }
          for(int j=i+1;j<n;j++){
            if(s[i]==t[j]){
              swap(s[j],t[j]);v.pb(mp(j+1,j+1));
            }
          }
          for(int j=i+1;j<n;j++){
            if(s[j]==s[i]){
              swap(t[i],s[j]);v.pb(mp(j+1,i+1));
              goto som;
            }
          }
          for(int j=i+1;j<n;j++){
            if(t[j]==t[i]){
              swap(s[i],t[j]);v.pb(mp(i+1,j+1));
              goto som;
            }
          }
        }
        som:
        int count=0;
      }
      cout<<v.size()<<endl;
      for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
      }
    }
  }
}
