#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long n,p,b,c;

int main(){
    scanf("%lld%lld%lld%lld",&n,&p,&b,&c);
    if(p>n*b)return puts("-1"),0;
    for(LL i=0;i<=b;i++){
        LL tmp=i*c;
        if(i>n)return puts("-1"),0;
        if(tmp==p)return printf("0 %lld %lld",i,n-i),0;
        if(tmp>p)return puts("-1"),0;
        if((p-tmp)%b==0){
            LL sum=(p-tmp)/b;
            if(sum+i>n)return puts("-1"),0;
            return printf("%lld %lld %lld",sum,i,n-sum-i),0;
        }
    }
    puts("-1");
}