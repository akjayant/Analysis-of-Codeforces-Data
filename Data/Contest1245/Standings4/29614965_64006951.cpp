#include<bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    int r,p,s;
    cin>>r>>p>>s;

    int rr=0,pp=0,ss=0,len=(n+1)/2,cnt=0;
    string sss;
    cin>>sss;

    for(int i=0;i<sss.size();i++) {
      if(sss[i]=='R')
        rr++;
      else if(sss[i] == 'P')
        pp++;
      else
        ss++;
    }

    cnt+=(r>=ss)?(ss):r;
    cnt+=(s>=pp)?(pp):s;
    cnt+=(p>=rr)?(rr):p;

    if(cnt<len) {
      cout<<"NO\n";
      continue;
    }

    cout<<"YES\n";
    string ans=sss;

    for(int i=0;i<sss.size();i++) {
      if(sss[i] == 'S' && r) {
        ans[i] = 'R';
        r--;
      }

      else if(sss[i] == 'R' && p) {
        ans[i] = 'P';
        p--;
      }

      else if(sss[i] == 'P' && s) {
        ans[i] = 'S';
        s--;
      }

      else {
        ans[i] = '#';
      }
    }

    for(int i=0;i<sss.size();i++) {
      if(ans[i] == '#') {
        if(r) {
          ans[i] = 'R';
          r--;
        }

        else if(s) {
          ans[i] = 'S';
          s--;
        }

        else {
          ans[i] = 'P';
          p--;
        }
      }
    }

    cout<<ans<<endl;
  }

  return 0;
}