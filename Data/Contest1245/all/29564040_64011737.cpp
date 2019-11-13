#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[100010];
int main(){
    int n;
    string s;
    while(cin>>s){
        ll ans=1;
        int n=s.size();
        dp[1]=1;
        dp[0]=1;
        ll mod=1e9+7;
        for(int i=2; i<=n; ++i){
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]%=mod;
        }
        for(int i=0; i<n; ++i){
            if(s[i]=='m' || s[i]=='w')
                ans=0;
            if(s[i]=='u'){
                int tmp=i;
                while(tmp+1<n&&s[tmp+1]==s[i]){
                    ++tmp;
                }
                ans*=dp[tmp-i+1];
                ans%=mod;
                i=tmp;
            }
            else if(s[i]=='n'){
                int tmp=i;
                while(tmp+1<n&&s[tmp+1]==s[i]){
                    ++tmp;
                }
                ans*=dp[tmp-i+1];
                ans%=mod;
                i=tmp;
            }
        }
        cout<<ans<<endl;
    }
  return 0;
}
