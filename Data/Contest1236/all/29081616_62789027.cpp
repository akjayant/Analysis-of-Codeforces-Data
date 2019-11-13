#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9+7;
int fp(int x , int y){
    if(y == 1)
        return x;
    if(y == 0)
        return 1;

    long long tem = fp(x , y /2)%mod;
    if(y%2)
        return 1LL*tem*tem%mod*x%mod;
    else
        return 1LL*tem*tem%mod;
}
int main(){
    int n , m;
    cin>>n>>m;
    cout<<fp( (fp(2,m) -1) , n);
    return 0;
}