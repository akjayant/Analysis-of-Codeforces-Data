#include <stdio.h>
int main(){
    int n;
    scanf("%i",&n);
    int A[300][300];
    int cnt=1;
    for(int j=0;j<n;j++){
        if(j&1)
            for(int i=0;i<n;i++) A[i][j]=cnt++;
        else
            for(int i=n-1;i>=0;i--) A[i][j]=cnt++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%i ",A[i][j]);
        printf("\n");
    }
}
