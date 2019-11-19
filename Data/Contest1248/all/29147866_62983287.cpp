#include"bits/stdc++.h"
using namespace std;

/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  long long h,w;h=w=0;
  cin>>n;
  int arr[n];
  for(int x=0;x<n;x++){
    cin>>arr[x];
  }
  sort(arr,arr+n);
  for(int x=0;x<n;x++){
    if(x<n/2)h+=arr[x];
    else w+=arr[x];
  }
  cout<<h*h + w*w;
  return 0;
}
