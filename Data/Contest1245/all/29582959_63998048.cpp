#include<bits/stdc++.h>
using namespace std;
int Q,a,b;
int main(){
    scanf("%d",&Q);
    while (Q--){
        int x,y;
        scanf("%d%d",&a,&b);
        if (__gcd(a,b)==1)printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}