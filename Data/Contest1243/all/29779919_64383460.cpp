//https://codeforces.com/contest/1243/problem/B1
#include<bits/stdc++.h>

using namespace std;

int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    char s1,t1;
    int mis_match=0;
    int  flag=0;
    for(int i=0;i<n;i++){
      if(mis_match==0 && s[i]!=t[i]){
        s1=s[i];
        t1=t[i];
        mis_match++;
      }
      else if(mis_match==1 && s[i]!=t[i] && s1==s[i] && t1==t[i]){
        mis_match++;
      }
      else if(s[i]!=t[i]){
        cout<<"NO\n";
        flag=1;
        break;
      }
    }
    if(flag==0 && mis_match==1){
      cout<<"NO\n";
      flag=1;
      continue;
    }
    if(flag==0) cout<<"YES\n";
  }
}
