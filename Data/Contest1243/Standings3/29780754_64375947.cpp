#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[10000];

int main(){
    int n,i,j,k,a,b,c;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%d",&arr[j]);
        }
        sort(arr+1,arr+n+1);
        a=0;
        for(j=n;j>=1;j--){
            if(arr[j]>=n-j+1){
                a=n-j+1;
            }
        }
        printf("%d\n",a);
    }
}
