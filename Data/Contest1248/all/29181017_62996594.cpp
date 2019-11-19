#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long a[100010]={0,2,4};
int n,m;
int main(){
    cin>>n>>m;
    for(int i=3;i<=max(n,m);i++){
        a[i]=(a[i-1]+a[i-2])%mod;
    }
    cout<<(a[n]+a[m]-2)%mod;
}
