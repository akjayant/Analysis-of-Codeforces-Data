#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
main()
{
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int f=0;
    char s1,s2,t1,t2;
    for(int i=0;i<n;i++){
      if(s[i]!=t[i]&&f==0){
        s1=s[i];
        t1=t[i];
        f=1;
      }
      else if(s[i]!=t[i]&&f==1){
        s2=s[i];
        t2=t[i];
        f=2;
      }
      else if(s[i]!=t[i]){
        f=5;break;
      }
    }
    if(f==5||f==1)cout<<"NO"<<endl;
    else if(f==0)cout<<"YES"<<endl;
    else {
      if(s1==s2&&t1==t2){
        cout<<"YES"<<endl;
      }
      else cout<<"NO"<<endl;
    }
  }
}
