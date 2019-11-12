#include <bits/stdc++.h>
using namespace std;
const long long D=1e9+7;
long long pow2(long long x,long long y){
    if(y==0)return 1;
    long long ret=pow2(x,y/2);
    ret=ret*ret%D;
    if(y%2==1)return ret*x%D;
    return ret;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long n,m;
    cin>>n>>m;
    cout<<pow2(pow2(2,m)-1,n);
    return 0;
}
