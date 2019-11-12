#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int i,j,k,a,b,c,n,t,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        k=0;
        for(x=0;x<=100;x++){
            for(y=0;y<=100;y++){
                if(x<=a&&2*x+y<=b&&2*y<=c){
                    k=max(k,3*(x+y));
                }
            }
        }
        printf("%d\n",k);
    }
}
