#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll inv(ll x){
    return power(x,mod-2);
}
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int a[333][333];
int main(){
    int n,i,j,temp=1;
    cin>>n;
    for(i=0;i<n;i++){
        if(i&1){
            for(j=n-1;j>=0;j--){
                a[j][i]=temp++;
            }
        }
        else{
            for(j=0;j<n;j++){
                a[j][i]=temp++;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
