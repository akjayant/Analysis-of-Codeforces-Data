#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a, b, c, d, k; int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int num1=(a+c-1)/c; int num2=(b+d-1)/d;
        if(num1+num2>k) printf("-1\n");
        else printf("%d %d\n",num1,num2);
    }
    return 0;
}
