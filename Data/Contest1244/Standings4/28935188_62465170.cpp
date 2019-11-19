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

void Solve(){
  int a,b,c,d,k;
  cin>>a>>b>>c>>d>>k;
  int pen=ceil((double)a/c),pencil=ceil((double)b/d);
  if(pen+pencil<=k){
    cout<<pen<<" "<<pencil<<endl;
  }else{
    cout<<-1<<endl;
  }

}

int main(void){
  cout << std::fixed << std::setprecision(16);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    Solve();
  }



  return 0;
}
