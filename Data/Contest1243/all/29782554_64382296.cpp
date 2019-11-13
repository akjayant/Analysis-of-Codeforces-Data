#include<iostream>
using namespace std;

char s1[10007],s2[10007];
int k,n,dist,ii,jj;

int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        scanf("%s%s",s1+1,s2+1);
        dist=0;
        ii=0;
        jj=0;
        for(int i=1;i<=n;i++){
            if(s1[i]!=s2[i]){
                if(ii==0)ii=i;
                else if(jj==0)jj=i;
                dist++;
            }
        }
        if(dist==0){
            printf("Yes\n");
        }
        else if(dist==2){
            if(s1[ii]==s1[jj]&&s2[ii]==s2[jj]){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}