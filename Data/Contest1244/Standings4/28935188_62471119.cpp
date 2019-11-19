#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cfloat>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int Solve(){
  int c;
  std::string s;
  cin>>c>>s;
  int leftest=-1;
  for(int i=0;i<c;i++){
    if(s[i]=='1'){
      leftest=i;
      break;
    }
  }
  int rightest=-1;
  for(int i=c-1;i>=0;i--){
    if(s[i]=='1'){
      rightest=i;
      break;
    }
  }
  if(leftest==-1){
    return c;
  }else{
    int left=std::max((c-leftest)*2,(leftest+1)*2);
    int right=std::max((c-rightest)*2,(rightest+1)*2);
    return std::max(left,right);
  }
}

int main(void){
  cout << std::fixed << std::setprecision(16);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cout<<Solve()<<endl;
  }



  return 0;
}
