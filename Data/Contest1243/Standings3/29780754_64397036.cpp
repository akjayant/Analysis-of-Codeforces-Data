#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    ll n,i,j,k,a,b,c,t;
    scanf("%lld",&n);
    a=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            a=i;
            break;
        }
    }
    if(a==0){
        printf("%lld",n);
        return 0;
    }
    b=n;
    while(b%a==0&&b>0){
        b/=a;
    }
    if(b==1){
        printf("%lld",a);
        return 0;
    }
    printf("1");
}
