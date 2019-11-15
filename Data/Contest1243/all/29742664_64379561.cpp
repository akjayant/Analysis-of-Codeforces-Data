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
  int flag=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=t[i]){
      for(int j=0;j<n;j++){
        if(j==i)
          continue;
        if(s[j]==s[i] && t[j]==t[i])
        {
          flag=1;
          swap(s[i],t[j]);
          break;
        }
      }
      if(flag==0)
      {
        cout<<"No\n";
        return ;
      }
      else
      {
        if(s==t)
        {
          cout<<"Yes\n";
        }
        else
        {
          cout<<"No\n";
        }
        return ;
      }
    }
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