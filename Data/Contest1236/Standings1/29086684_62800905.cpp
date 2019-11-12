#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k;
    int n;
    scanf("%d",&n);
    if(n&1){
       k=1;
       for(i=1,j=n*n;i<j-n;i++,j--){
            printf("%d ",i);
            printf("%d ",j);
            if(i%(n/2)==0 && (n*n-j+1)%(n/2)==0){
                printf("%d\n",n*(n/2)+k);
                k++;
            }
        }
    }
    else {
        for(i=1,j=n*n;i<j;i++,j--){
            printf("%d ",i);
            printf("%d ",j);
            if(i%(n/2)==0 && (n*n-j+1)%(n/2)==0)
                printf("\n");
        }
    }
}
