#include <stdio.h>
int main(){
    short int t;
    scanf("%hi",&t);
    while(t--){
        short int a,b,c;
        scanf("%hi%hi%hi",&a,&b,&c);
        short int ans=(b<c/2 ? b:c/2);
        b-=ans;
        ans*=3;
        printf("%hi\n",ans+3*(a<b/2 ? a:b/2));
    }
}
