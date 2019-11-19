#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[100100],mod=1000000007;

int main(){

ll n,m,br=0;

cin>>n>>m;

dp[1]=0;
dp[2]=1;
for(int i=3;i<=100000;++i)dp[i]=(dp[i-1]+dp[i-2]+1)%mod;
cout<<((dp[n]+dp[m])*2+2)%mod<<endl;

return 0;
}
