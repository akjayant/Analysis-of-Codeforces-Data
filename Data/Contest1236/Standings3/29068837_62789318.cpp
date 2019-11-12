#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6+50;
const int MOD = 1e9+7;
LL quick_pow(LL a,LL b){
    LL res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<quick_pow(quick_pow(2,m)-1,n)<<endl;
}
