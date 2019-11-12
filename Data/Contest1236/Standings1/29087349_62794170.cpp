#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define IOS cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

int power(int a,int b){
    int ret=1;
    for(int k=a;b;b>>=1,k=k*k%mod){
        if(b&1){
            ret=ret*k%mod;
        }
    }return ret;
}
signed main()
{IOS;
    int a,b;
    cin>>a>>b;
    int u=power(2,b);
    u=(u-1+mod)%mod;
    cout<<power(u,a)<<endl;
    return 0;
}

/*
*/

