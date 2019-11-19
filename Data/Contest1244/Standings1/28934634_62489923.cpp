#include<iostream>
#include<cstdio>
int main() {
    int T,a,b,c,d,k;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        a=(a+c-1)/c;
        b=(b+d-1)/d;
        if(a+b>k) printf("-1\n");
        else printf("%d %d\n",a,b);
    }
    return 0;
}
