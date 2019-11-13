#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 305;
int a[N][N],n;

int main(){
    scanf("%d",&n);
    for(int j=1;j<=n;++j){
        if(j&1){
            for(int i=1;i<=n;++i){
                a[i][j]=i+(j-1)*n;
            }
        }
        else{
            for(int i=1;i<=n;++i){
                a[n+1-i][j]=i+(j-1)*n;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}