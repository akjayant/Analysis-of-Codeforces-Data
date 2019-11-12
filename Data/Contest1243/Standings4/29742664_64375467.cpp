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
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  int mx=-1;
  for(int i=n-1;i>=0;i--){
    int cp=min(arr[i],n-i);
    mx=max(cp,mx);
  } 
  cout<<mx<<endl;
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