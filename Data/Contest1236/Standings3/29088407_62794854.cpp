#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

int arr[305][305];

int main(){
    int i,j,k,a,b,c=1,n,m,t,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i%2==1)arr[j][i]=c++;
            else arr[n-j+1][i]=c++;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)printf("%d ",arr[i][j]);
        printf("\n");
    }
}
