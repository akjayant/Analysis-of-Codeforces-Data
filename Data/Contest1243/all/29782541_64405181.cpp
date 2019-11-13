#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> Paint;
int alp[26];
void init(){
  for(int i = 0; 26 > i; i++){
    alp[i] = 0;
  }
}
int main(){
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    init();

    int n;cin>>n;
    string s,t;cin>>s>>t;
    for(int i = 0; n > i; i++){
      alp[s[i]-'a']++;
      alp[t[i]-'a']++;
    }
    bool ok = true;
    for(int i = 0; 26 > i; i++){
      if(alp[i]%2){
        ok = false;
        break;
      }
    }
    if(!ok){
      cout << "no" << endl;
      continue;
    }
    cout << "yes" << endl;
    vector<Paint> ans;
    vector<pair<pair<char,char>,int> > a;
    for(int i = 0; n > i; i++){
      if(s[i] != t[i]){
        a.push_back({{s[i],t[i]},i});
      }
    }
    int nw = 0;
    while(nw < a.size()){
      for(int i = 0; n > i; i++){
        if(a[i].first.first == a[i].first.second)continue;
        if(nw == i)continue;
        if(a[nw].first.second == a[i].first.first || a[nw].first.second == a[i].first.second){
          if(a[nw].first.second == a[i].first.first){
            if(a[nw].first.first == a[i].first.second){
              ans.push_back({a[i].second,a[i].second});
              swap(a[i].first.first,a[i].first.second);
              ans.push_back({a[i].second,a[nw].second});
              swap(a[i].first.first,a[nw].first.second);
              break;
            }else{
              ans.push_back({a[i].second,a[i].second});
              swap(a[i].first.first,a[i].first.second);
              ans.push_back({a[nw].second,a[i].second});
              swap(a[nw].first.first,a[i].first.second);
              break;
            }
          }else{
            if(a[nw].first.first == a[i].first.first){
              ans.push_back({a[nw].second,a[i].second});
              swap(a[nw].first.first,a[i].first.second);
              break;
            }else{
              ans.push_back({a[nw].second,a[i].second});
              swap(a[nw].first.first,a[i].first.second);
              break;
            }
          }
        }
      }
      while(a[nw].first.first == a[nw].first.second)nw++;
    }
    cout << ans.size() << endl;
    for(int i = 0; ans.size() > i; i++){
      cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    a.clear();
    ans.clear();
  }
}