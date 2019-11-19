#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;scanf("%lld",&n);
    ll z=sqrt(n);
    vector<ll> a;
    for(int i=2;i<=z;i++){
        if(n%i==0){
            a.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n!=1){
        a.push_back(n);
    }
    if(a.size()==1){
        printf("%lld\n",a[0]);
    }
    else{
        puts("1");
    }
}