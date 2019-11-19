#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
vector<LL> divi;
void f(LL x){
    for(LL i=2;i*i<=x;i++){
        if(x%i==0){
            divi.push_back(i);
        }
    }
}
int main(){
    scanf("%lld",&n);
    f(n);
    if(n==1){
        printf("1");
        return 0;
    }
    if(divi.size()==0){
        printf("%lld",n);
        return 0;
    }
    LL tmp=n;
    while(n>1 && n%divi.front()==0){
        n/=divi.front();
    }
    if(n==1){
        printf("%lld",divi.front());
    }
    else{
        printf("1");
    }
}
