#include<bits/stdc++.h>
#define IO cin.tie(0);ios_base::sync_with_stdio(false);
#define int long long 
#define endl '\n'
#define mod 1000000007

using namespace std;

int dp(int num){
    int a=2,b=2;
    int temp;
    for(int i=0;i<num;i++){
        a+=b;
        temp = b;
        b = a;
        a = temp;
        a%=mod;
        b%=mod;
    }
    return a;
}

signed main(){
    IO
    int m,n;
    cin>>m>>n;
//    cout<<dp(m)<<'\t'<<dp(n)<<endl;
    cout<<(dp(m)+dp(n)-2)%mod<<endl;

    return 0;
}
