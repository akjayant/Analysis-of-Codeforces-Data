#include<bits/stdc++.h>
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define int long long int
#define modulo 1000000007
using namespace std;

int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      string s;
      cin>>s;
      int n=s.length();
      vector<int> U,N;
      int cnt=0;
      for(int i=0;i<n;i++){
            if(s[i]=='m'||s[i]=='w'){
                  cout<<0;
                  return 0;
            }
      }
      for(int i=0;i<n;i++){
            if(s[i]=='u'){
                  cnt++;
            }
            else if(i>0&&s[i-1]=='u'){
                  U.pb(cnt);
                  cnt=0;
            }
      }
      if(s[n-1]=='u')U.pb(cnt);
      cnt=0;
      for(int i=0;i<n;i++){
            if(s[i]=='n'){
                  cnt++;
            }
            else if(i>0&&s[i-1]=='n'){
                  N.pb(cnt);
                  cnt=0;
            }
      }
      if(s[n-1]=='n')N.pb(cnt);
      cnt=0;
      vector<int> dp(n+1,1);
      for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%modulo;
      }
      int ans=1;
      for(int i=0;i<U.size();i++){
            ans=ans*dp[U[i]]%modulo;
      }
      for(int i=0;i<N.size();i++){
            ans=ans*dp[N[i]]%modulo;
      }
      cout<<ans;
}

