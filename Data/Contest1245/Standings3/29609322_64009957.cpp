#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define LL long long
#define pii pair<int,int>
#define MEM(x,y) memset(x,y,sizeof(x))
#define bug(x) cout<<"debug "#x" is "<<x<<endl;
#define FIO ios::sync_with_stdio(false);
#define ALL(x) x.begin(),x.end()
#define LOG 20
const int inf =1e9;
const int maxn =3e5+7;
const int mod = 1e9+7;
LL dp[maxn];
LL add(LL a,LL b){return (a+b)%mod;};
int main(){
    FIO;
    string s;
    cin>>s;
    dp[0]=dp[1]=1;
    for(auto c:s){
        if(c=='m'||c=='w'){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=1;i<s.size();i++){
        if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n')){
            dp[i+1]=add(dp[i],dp[i-1]);
        }
        else
            dp[i+1]=dp[i];
    }
    cout<<dp[s.size()]<<endl;
    return 0;
}


