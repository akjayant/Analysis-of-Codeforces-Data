#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,d,sq;
    scanf("%lld",&n);
    d=n;
    sq=sqrt(n);
    for(long long i=2;i<=sq;i++){
        if(n%i==0){
            if(d==n) d=i;
            else if(i%d!=0) return !printf("1");
        }
    }
    int k=0;
    while(n%d==0LL){
       n/=d;
       if(n==1LL) break;
       assert(k<1000);
    }
    printf("%lld",n==1LL?d:1LL);


}
