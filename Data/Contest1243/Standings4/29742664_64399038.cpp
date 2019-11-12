/*
    ##############################
    ## Author: Abhinav Batta #####
    ## College: IIIT-Allahabad ###
    ##############################
 
*/  
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  int fre1[26];
  int fre2[26];
  for(int i=0;i<26;++i)
    fre1[i]=fre2[i]=0;
  for(int i=0;i<n;i++){
    fre1[s[i]-'a']++;
    fre2[t[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if(((fre1[i]+fre2[i])%2)!=0)
    {
      cout<<"No\n";
      return ;
    }
  }
  int moves=0;
  vector<int> v1,v2;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=t[i]){
      int idx=-1;
      int flag=0;
      for(int j=i+1;j<n;j++){
        if(s[j]==t[j])
          continue;
        if(s[j]==s[i])
        {
          flag=1;
          idx=j;
          break;
        }
        else if(t[j]==s[i])
        {
          idx=j;
        }
      }
      if(idx==-1)
      {
        cout<<"fault\n";
        return ;
      }
      if(flag){
        moves++;
        swap(s[idx],t[i]);
        v1.push_back(idx+1);
        v2.push_back(i+1);
      }
      else{
        moves+=2;
        swap(s[idx],t[idx]);
        v1.push_back(idx+1);
        v2.push_back(idx+1);
        swap(s[idx],t[i]);
        v1.push_back(idx+1);
        v2.push_back(i+1);  
      }
    }
  }
  if(moves>2*n){
    cout<<"No\n";
  }
  else
  {
      cout<<"Yes\n";
    cout<<moves<<endl;
    for(int i=0;i<moves;i++)
      cout<<v1[i]<<" "<<v2[i]<<endl;
  }
}
int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;
     while(t--)
     solve();    
     return 0;
}