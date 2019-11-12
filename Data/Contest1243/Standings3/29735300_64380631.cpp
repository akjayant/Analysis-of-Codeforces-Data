#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;

int t,n;
char a[10000+5];
char b[10000+5];

int main(){
    scanf("%d",&t);
    while(t--){
        int tot=0,pos1=0,pos2=0;
        scanf("%d",&n);
        scanf("%s%s",a+1,b+1);
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                tot++;
                if(!pos1)pos1=i;
                else pos2=i;
            }
        }
        if(tot==0)printf("Yes\n");
        else if(tot==2){
            if(a[pos1]==a[pos2]&&b[pos1]==b[pos2])printf("Yes\n");
            else printf("No\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

