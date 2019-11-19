#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
#include<cmath>
using namespace std;

long long n;

int main(){
    bool flag=true;
    long long chushu=0;
    cin>>n;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0){chushu=i;flag=false;break;}
    }
    while(chushu&&n%chushu==0){n/=chushu;}
    if(flag){
        cout<<n;
    }else if(n==1){
        cout<<chushu;
    }else{
        cout<<1;
    }
    return 0;
}

