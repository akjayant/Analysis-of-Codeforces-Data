//
// Created by StupidTurtle on 2019/10/17.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        int mx=0;
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                if(i<=a&&i*2+j<=b&&j*2<=c){
                    mx=max(mx,i*3+j*3);
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}