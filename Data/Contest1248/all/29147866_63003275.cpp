#include"bits/stdc++.h"
using namespace std;

/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,best=0,cur=0;//best refers to number of stuff added...
  string a;
  cin>>n>>a;
  pair<int,int> bp=make_pair(0,0),lowest_num;
  for(int x=0;x<n;x++){
    if(a[x]=='(')cur++;
    else cur--;
  }
  if(cur!=0){
    cout<<"0\n1 1";
    return 0;
  }

  lowest_num=make_pair(0,1);//number, and the number of times it has appeared...
  cur=0;
  for(int z=0;z+1<n;z++){
    if(a[z]=='(')cur++;
    else cur--;
    if(cur==lowest_num.first)lowest_num.second++;
    else if(cur<lowest_num.first){
      lowest_num=make_pair(cur,1);
    }
  }
  best=lowest_num.second;

  for(int x=0;x<n;x++){
    for(int y=x+1;y<n;y++){
      if(a[x]==a[y])continue;
      swap(a[x],a[y]);
      lowest_num=make_pair(0,1);//number, and the number of times it has appeared...
      cur=0;
      for(int z=0;z+1<n;z++){
        if(a[z]=='(')cur++;
        else cur--;
        if(cur==lowest_num.first)lowest_num.second++;
        else if(cur<lowest_num.first){
          lowest_num=make_pair(cur,1);
        }
      }
      swap(a[x],a[y]);
      if(lowest_num.second>=best){
        best=lowest_num.second;
        bp=make_pair(x,y);
      }
    }
  }
  cout<<best<<'\n'<<bp.first+1<<' '<<bp.second+1;
  return 0;
}
