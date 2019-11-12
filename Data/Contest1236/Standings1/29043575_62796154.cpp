#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 300+5;
int ans[maxn][maxn];
int check_ans(int n){
    int minv = 0x3f3f3f3f;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            int cnt=0;
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    if(ans[a][i]>ans[b][j]){
                        cnt++;
                    }
                }
            }
            minv=  min(minv,cnt);
        }
    }
    printf("%d %d\n",n*n/2,minv);
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=n*n;
    for(int i=0;i<n;i++){
        if(i&1){
            for(int j=n-1;j>=0;j--){
                ans[i][j]=cnt;
                cnt--;
            }
        }
        else{
            for(int j=0;j<n;j++){
                ans[i][j]=cnt;
                cnt--;
            }
        }
    }
    //check_ans(n);
    for(int j=0;j<n;j++){
        printf("%d",ans[0][j]);
        for(int i=1;i<n;i++){
            printf(" %d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
