#include<iostream>
#include<algorithm>
using namespace std;
int k,n,a[1007],h;
int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        h=0;
        for(int i=n;i>=1;i--){
            if(a[i]>=h+1){
                h++;
            }
            else{
                break;
            }
        }
        printf("%d\n",h);
    }
    return 0;
}