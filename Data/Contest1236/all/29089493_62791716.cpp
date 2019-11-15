#include <stdio.h>
long long pow(long long p,long long x=2){
    if(!p) {
        //printf("%lli\n",1);
        return 1;
    }
    if(p&1) {
        return ((x%1000000007)*pow(p-1,x))%1000000007;
    }
    long long k=pow((p>>1),x);
    return (k*k)%1000000007;
}
int main(){
    long long n,m;
    scanf("%lli%lli",&n,&m);
    //printf("%lli\n",pow(3));
    printf("%lli",pow(n,(pow(m)-1)));
}
