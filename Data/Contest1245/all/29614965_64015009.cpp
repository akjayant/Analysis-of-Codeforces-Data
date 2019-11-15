#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  string s;
  cin>>s;

  vector<ll> tmp;
  int i,flag = 0;

  ll fib[s.size()+1],mod=1e9+7;
  fib[0] = fib[1] = 1;

  for(i=2;i<=s.size();i++)
    fib[i] = (fib[i-1] + fib[i-2])%mod;

  for(i=0;i<s.size();) {

    if(s[i] == 'm' || s[i]=='w') {
      flag = 1;
      i++;
      continue;
    }

    else if(s[i] == 'u' || s[i] == 'n') {
      int j = i,cnt=0;

      while(j<s.size() &&  s[j]==s[i]) {
        cnt++;
        j++;
      }

      tmp.push_back(cnt);
      i=j;
    }

    else
      i++;
  }

  if(flag == 1) {
    cout<<0<<endl;
    return 0;
  }

  ll ans = 1;

  for(i=0;i<tmp.size();i++) {
    ans = (ans*fib[tmp[i]])%mod;
  }

  cout<<ans<<endl;
  return 0;
}