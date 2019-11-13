//
// Created by StupidTurtle on 2019/10/17.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mp[305][305];
int main(){
    int n;scanf("%d",&n);
    int top=n*n;
    for(int i=1;i<=n;i+=2){
        int tmp=top-(i-1)*n;
        for(int j=1;j<=n;j++){
            mp[j][i]=tmp-j+1;
        }
    }
    for(int i=2;i<=n;i+=2){
        int tmp=top-(i-1)*n;
        for(int j=n;j>=1;j--){
            mp[j][i]=tmp-(n-j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d%c",mp[i][j],(j==n)?'\n':' ');
        }
    }
    return 0;
}