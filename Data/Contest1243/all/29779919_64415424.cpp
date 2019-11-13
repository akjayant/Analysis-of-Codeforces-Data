//https://codeforces.com/contest/1243/problem/B1
#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    // cout<<s<<"\n";
    // cout<<t<<"\n";
    set<int> cnt1[26];
    set<int> cnt2[26];
    for(int i=0;i<n;i++){
      cnt1[s[i]-'a'].insert(i);
      cnt2[t[i]-'a'].insert(i);
    }
    int flag=0;
    for(int i=0;i<26;i++){
      if((cnt1[i].size()+cnt2[i].size())%2){
        cout<<"No\n";
        flag=1;
        break;
      }
    }
    if(flag==1) continue;
    cout<<"Yes\n";
    vector<pair<int,int>> moves;
    for(int i=0;i<s.size();i++){
      // cout<<i<<" hhell\n";
      if(s[i]==t[i]){
        cnt1[s[i]-'a'].erase(cnt1[s[i]-'a'].begin());
        cnt2[s[i]-'a'].erase(cnt2[t[i]-'a'].begin());
        continue;
      }
      else{
        cnt1[s[i]-'a'].erase(cnt1[s[i]-'a'].begin());
        if(!cnt1[s[i]-'a'].empty()){
         int tmp=*(cnt1[s[i]-'a'].begin());
         // cout<<tmp<<" tmp val\n";
         cnt1[s[i]-'a'].erase(cnt1[s[i]-'a'].begin());
         moves.pb({tmp+1,i+1});
         cnt1[t[i]-'a'].insert(tmp);
         cnt2[t[i]-'a'].erase(cnt2[t[i]-'a'].begin());
         s[tmp]=t[i];
         // cout<<tmp+1<<" "<<i+1<<"\n";
         // cout<<" lkaaa\n";
         }
        else{
          cnt2[t[i]-'a'].erase(cnt2[t[i]-'a'].begin());
          cnt1[s[i+1]-'a'].erase(cnt1[s[i+1]-'a'].begin());
          int tmp=*(cnt2[s[i]-'a'].begin());
          cnt2[s[i]-'a'].erase(cnt2[s[i]-'a'].begin());
          cnt2[s[i+1]-'a'].insert(tmp);
          cnt1[t[i]-'a'].insert(i+1);
          swap(s[i+1],t[tmp]);
          swap(s[i+1],t[i]);
          moves.pb({i+2,tmp+1});
          moves.pb({i+2,i+1});
          // cout<<i+1+1<<" "<<tmp+1<<"\n";
          // cout<<i+1+1<<" "<<i+1<<"\n";
        }
      }
    }
    cout<<moves.size()<<"\n";
    for(int i=0;i<moves.size();i++){
      cout<<moves[i].f<<" "<<moves[i].s<<"\n";
    }
    // cout<<"reached\n";
  }
}
