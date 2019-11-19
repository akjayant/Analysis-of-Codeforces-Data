#include<iostream>
#include<cmath>
using namespace std;

long long int n,minx,lin,sum,ok=1;

int main(){
    scanf("%lld",&n);
    minx=100000000000000;
    ok=1;
    for(long long int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(minx==100000000000000){
                minx=i;
                lin=n/i;
                if(lin%minx==0){
                    continue;
                }
                else{
                    ok=0;
                    break;
                }
            }
            else{
                if(i%minx!=0){
                    ok=0;
                    break;
                }
                lin=n/i;
                if(lin%minx!=0){
                    ok=0;break;
                }
            }
        }
        
    }
    if(minx==100000000000000){
        printf("%lld\n",n);
    }
    else if(ok==0){
        printf("1\n");
    }
    else{
        printf("%lld\n",minx);
    }
    return 0;
}