#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int q;cin>>q;
  vector<char> a;
  for(int i = 0; q > i; i++){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    for(int i = 0; n > i; i++){
      if(s[i]!=t[i]){
        a.push_back(s[i]);
        a.push_back(t[i]);
      }
    }
    if(a.size() != 4){
      cout << "no" << endl;
      a.clear();
      continue;
    }
    if(a[0] == a[2] && a[1] == a[3]){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
    a.clear();
  }
}