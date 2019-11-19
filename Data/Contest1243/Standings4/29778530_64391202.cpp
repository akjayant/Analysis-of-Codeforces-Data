//
// Created by StupidTurtle on 2019/11/6.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> vec;
int main(){
    ll n;scanf("%lld",&n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(ll i=2ll;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            vec.push_back(i);
        }
    }
    if(n!=1) vec.push_back(n);
    if(vec.size()>=2) printf("1\n");
    else printf("%lld\n",vec[0]);
    return 0;
}